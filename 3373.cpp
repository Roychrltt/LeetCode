#include <bits/stdc++.h>

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
	int n = edges1.size(), m = edges2.size();
	std::vector<std::vector<int>> next1(n + 1), next2(m + 1);
	for (const auto& e : edges1)
	{
		int x = e[0], y = e[1];
		next1[x].push_back(y);
		next1[y].push_back(x);
	}
	for (const auto& e : edges2)
	{
		int x = e[0], y = e[1];
		next2[x].push_back(y);
		next2[y].push_back(x);
	}
	auto dfs = [&](this auto&& dfs, const vector<vector<int>>& adj, int u, int parent, vector<int>& color, int& evenCnt, int& oddCnt) -> void {
		if (color[u] == 0) evenCnt++;
		else oddCnt++;
		for (int v : adj[u]) if (v != parent) {
			color[v] = color[u] ^ 1;
			dfs(adj, v, u, color, evenCnt, oddCnt);
		}
	};
	vector<int> color1(n, -1), color2(m, -1);
	int even1 = 0, odd1 = 0, even2 = 0, odd2 = 0;
	color1[0] = 0;
	dfs(next1, 0, -1, color1, even1, odd1);
	color2[0] = 0;
	dfs(next2, 0, -1, color2, even2, odd2);
	int mx = max(even2, odd2);
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		ans[i] = (color1[i] == 0 ? even1 : odd1) + mx;
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
