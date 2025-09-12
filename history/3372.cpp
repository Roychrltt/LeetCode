#include <bits/stdc++.h>

std::vector<int> f(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2, int k)
{
	int n1 = edges1.size() + 1;
	int n2 = edges2.size() + 1;
	std::vector<std::vector<int>> next1(n1), next2(n2);
	for (const auto& e : edges1) {
		int x = e[0], y = e[1];
		next1[x].push_back(y);
		next1[y].push_back(x);
	}
	for (const auto& e : edges2) {
		int x = e[0], y = e[1];
		next2[x].push_back(y);
		next2[y].push_back(x);
	}

	std::vector<int> vis(n2 + 1);
	int mx = 0;
	auto dfs = [&](this auto&& dfs, int node, int cur,
			std::vector<std::vector<int>>& next) {
		if (cur > k)
			return;

		vis[node] = 1;
		for (int x : next[node])
			if (!vis[x])
				dfs(x, cur + 1, next);
	};
	for (int i = 0; i < n2; i++) {
		dfs(i, 1, next2);
		mx = std::max(mx, std::accumulate(vis.begin(), vis.end(), 0));
		for (int& a : vis)
			a = 0;
	}

	int cnt = mx;
	vis.clear();
	vis.resize(n1);
	std::vector<int> ans(n1);
	for (int i = 0; i < n1; i++) {
		mx = 0;
		dfs(i, 0, next1);
		mx = std::max(mx, std::accumulate(vis.begin(), vis.end(), 0));
		for (int& a : vis)
			a = 0;
		ans[i] = cnt + mx;
	}
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
