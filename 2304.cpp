#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minPathCost(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& moveCost) {
	int m = grid.size(), n = grid[0].size();
	std::vector<std::vector<int>> f(m, std::vector<int>(n, INT_MAX));
	f[m - 1] = grid[m - 1];
	for (int i = m - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				f[i][j] =
					std::min(f[i][j], f[i + 1][k] + moveCost[grid[i][j]][k]);
			}
			f[i][j] += grid[i][j];
		}
	}
	return *min_element(f[0].begin(), f[0].end());
}

int minPathCost(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& moveCost) {
	int m = grid.size(), n = grid[0].size();
	for (int i = m - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			int tmp = std::numeric_limits<int>::max();
			for (int k = 0; k < n; k++) {
				tmp = std::min(tmp, grid[i + 1][k] + moveCost[grid[i][j]][k]);
			}
			grid[i][j] += tmp;
		}
	}
	return *min_element(grid[0].begin(), grid[0].end());
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 99.28%
// memory beats 93.19%
