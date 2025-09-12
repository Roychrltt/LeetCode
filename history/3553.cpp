#include <bits/stdc++.h>

class Solution {
	public:
		int minMoves(vector<string>& grid) {
			int m = grid.size(), n = grid[0].size();
			unordered_map<char, vector<pair<int, int>>> map;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (isalpha(grid[i][j]))
						map[grid[i][j]].push_back({i, j});
			std::vector<std::pair<int, int>> dirs = {
				{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
			std::vector<std::vector<int>> v(m, std::vector<int>(n, 1e9));
			std::priority_queue<std::pair<int, std::pair<int, int>>,
				std::vector<std::pair<int, std::pair<int, int>>>,
				std::greater<std::pair<int, std::pair<int, int>>>>
					q;

			std::pair<int, int> p = {0, 0};
			std::pair<int, std::pair<int, int>> pp = {0, p};
			q.push(pp);
			char c = grid[0][0];
			if (isalpha(c) && map[c].size() > 1) {
				for (auto& [x, y] : map[c]) {
					if (x != 0 || y != 0) {
						p = {x, y};
						pp = {0, p};
						q.push(pp);
					}
				}
				map.erase(c);
			}
			int ans = 1e9;
			while (!q.empty()) {
				int vv = q.top().first;
				int i = q.top().second.first;
				int j = q.top().second.second;
				q.pop();
				if (vv > ans) break;
				if (i == m - 1 && j == n - 1)
					ans = min(ans, vv);
				for (auto [dx, dy] : dirs) {
					int ni = i + dx;
					int nj = j + dy;
					if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
							grid[ni][nj] != '#' && v[ni][nj] > vv + 1) {
						c = grid[ni][nj];
						v[ni][nj] = vv + 1;
						p = {ni, nj};
						pp = {v[ni][nj], p};
						q.emplace(pp);
						if (isalpha(c) && map.count(c) > 0){
							for (auto& [x, y] : map[c]) {
								if (x != ni || y != nj) {
									v[x][y] = v[ni][nj];
									p = {x, y};
									pp = {v[ni][nj], p};
									q.push(pp);
								}
							}
							map.erase(c);
						}
					}
				}
			}
			return ans == 1e9 ? -1 : ans;
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
