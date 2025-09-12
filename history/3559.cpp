#include <bits/stdc++.h>

class Solution {
	const int MOD = 1e9 + 7;
	long long fastPower(long long x, long long p) {
		long long res = 1;
		while (p) {
			if (p & 1)
				res = (res * x) % MOD;
			p >>= 1;
			x = (x * x) % MOD;
		}
		return res;
	}

	public:
	vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
		int n = edges.size() + 1;
		vector<vector<int>> next(n + 1);
		for (auto& e : edges) {
			next[e[0]].push_back(e[1]);
			next[e[1]].push_back(e[0]);
		}

		vector<int> depth(n + 1);
		vector<vector<int>> up(n + 1, vector<int>(20, -1));

		auto dfs = [&](this auto&& dfs, int node, int parent) -> void {
			up[node][0] = parent;
			for (int i = 1; i < 20; i++) {
				if (up[node][i - 1] != -1)
					up[node][i] = up[up[node][i - 1]][i - 1];
			}
			for (int v : next[node]) {
				if (v != parent) {
					depth[v] = depth[node] + 1;
					dfs(v, node);
				}
			}
		};

		dfs(1, -1);

		auto lca = [&](int u, int v) {
			if (depth[u] < depth[v])
				swap(u, v);
			for (int i = 19; i >= 0; --i)
				if (up[u][i] != -1 && depth[up[u][i]] >= depth[v])
					u = up[u][i];
			if (u == v)
				return u;
			for (int i = 19; i >= 0; --i)
				if (up[u][i] != -1 && up[u][i] != up[v][i]) {
					u = up[u][i];
					v = up[v][i];
				}
			return up[u][0];
		};

		vector<int> ans;
		for (auto& q : queries) {
			int u = q[0], v = q[1];
			int an = lca(u, v);
			int d = depth[u] + depth[v] - 2 * depth[an];
			if (d == 0)
				ans.push_back(0);
			else
				ans.push_back(fastPower(2, d - 1));
		}

		return ans;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
