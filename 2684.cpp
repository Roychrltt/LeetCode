#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <functional>

// dfs, space optimization by setting visited grid to 0
int f(std::vector<std::vector<int>>& grid)
{
	int ans = 0;
	int m = grid.size(), n = grid[0].size();
	std::function<void(int, int)> dfs = [&](int i, int j) {
		ans = std::max(ans, j);
		if (ans == n - 1)
			return;
		for (int k = std::max(0, i - 1); k < std::min(m, i + 2); k++)
		{
			if (grid[k][j + 1] > grid[i][j])
				dfs(k, j + 1);
		}
		grid[i][j] = 0;
	};
	for (int i = 0; i < m; i++)
		dfs(i, 0);
	return ans;
}

// bfs
int f(std::vector<std::vector<int>>& grid)
{
	int m = grid.size(), n = grid[0].size();
	for (auto& row : grid)
		row[0] *= -1;
	for (int j = 0; j < n - 1; j++)
	{
		bool ok = false;
		for (int i = 0; i < m; i++)
		{
			if (grid[i][j] > 0)
				continue;
			for (int k = std::max(0, i - 1); k < std::min(m, i + 2); k++)
			{
				if (grid[k][j + 1] > -grid[i][j])
				{
					grid[k][j + 1] *= -1;
					ok = true;
				}
			}
		}
		if (!ok)
			return j;
	}
	return n - 1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 98.77%
