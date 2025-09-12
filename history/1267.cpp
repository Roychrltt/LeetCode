#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int countServers(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid[0].size();
	vector<int> row(m), col(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j])
			{
				row[i]++;
				col[j]++;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] && (row[i] >= 2 || col[j] >= 2))
				count++;
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
// runtime beats 100%
// memory beats 39.90%
