#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> zigzagTraversal(std::vector<std::vector<int>>& grid) {
	int m = grid.size(), n = grid[0].size();
	int d = 1;
	std::vector<int> v;
	bool count = true;
	int j;
	for (int i = 0; i < m; i++)
	{
		j = d > 0 ? 0 : n - 1;
		while(j >= 0 && j < n)
		{
			if (count) v.push_back(grid[i][j]);
			j += d;
			count ^= 1;
		}
		d = -d;
	}
	return v;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 50%
