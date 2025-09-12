#include <bits/stdc++.h>

class Solution {
	const int MOD = 1e9 + 7;
	long long fastPower(long long x, long long p)
	{
		long long res = 1;
		while (p)
		{
			if (p & 1) res = (res * x) % MOD;
			p >>= 1;
			x = (x * x) % MOD;
		}
		return res;
	}
	public:
	int assignEdgeWeights(vector<vector<int>>& edges) {
		int n = edges.size() + 1;
		vector<vector<int>> next(n + 1);
		for (auto& e : edges)
		{
			next[e[0]].push_back(e[1]);
			next[e[1]].push_back(e[0]);
		}
		int cnt = 0;
		auto dfs = [&](this auto&& dfs, int node, int parent, int depth) -> void {
			cnt = max(cnt, depth);
			for (int x : next[node]) {
				if (x != parent)
					dfs(x, node, depth + 1);
			}
		};
		dfs(1, -1, 0);
		if (cnt == 0) return 0;
		return fastPower(2, cnt - 1);
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
