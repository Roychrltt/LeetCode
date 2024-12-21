#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int numIslands(std::vector<std::vector<char>>& grid) {
	if (grid.empty()) return 0;

	int ans = 0, rows = grid.size(), cols = grid[0].size();
	std::vector<std::pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	auto bfs = [&](int i, int j) {
		std::queue<std::pair<int, int>> q;
		q.push({i, j});
		grid[i][j] = '0';

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for (auto [dx, dy] : directions) {
				int nx = x + dx, ny = y + dy;
				if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
					q.push({nx, ny});
					grid[nx][ny] = '0'; 
				}
			}
		}
	};

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (grid[i][j] == '1') { 
				++ans;
				bfs(i, j); 
			}
		}
	}

	return ans;
}

void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 91.02%
// memory beats 87.92%
