#include <bits/stdc++.h>

class Solution {
	public:

		int largestPathValue(string colors, vector<vector<int>> &edges) {
			int n = colors.size();
			vector<vector<int>> next(n), count(n, vector<int>(26));
			vector<int> vis(n);
			for (auto &e : edges)
			{
				if (e[0] == e[1]) return -1;
				next[e[0]].push_back(e[1]);
			}

			int ans = 0;
			auto dfs = [&](this auto&& dfs, int node) -> void
			{
				if (vis[node] == 1)
				{
					ans = INT_MAX;
					return;
				}
				if (vis[node] == 2) return;
				vis[node] = 1;
				for (int next : next[node]) {
					dfs(next);
					if (ans == INT_MAX) return;
					for (int c = 0; c < 26; c++)
						count[node][c] = max(count[node][c], count[next][c]);
				}
				count[node][colors[node] - 'a']++;
				vis[node] = 2;
				ans = max(ans, count[node][colors[node] - 'a']);
			};

			for (int i = 0; i < n && ans != INT_MAX; i++)
				dfs(i);
			return ans == INT_MAX ? -1 : ans;
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
