#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minimumOperations(vector<vector<int>>& grid) {
	int ans = 0;
	int m = grid.size(), n = grid[0].size();
	for (int col = 0; col < n; col++)
	{
		for (int row = 1; row < m; row++)
		{
			int cur = grid[row][col];
			int prev = grid[row - 1][col];
			if (cur <= prev)
			{
				int d = prev - cur + 1;
				ans += d;
				grid[row][col] += d;
			}
		}
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
// runtime beats 100%
// memory beats 8.33%
