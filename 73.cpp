#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

void setZeroes(std::vector<std::vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	std::vector<bool> row(m), col(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				row[i] = true;
				col[j] = true;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (row[i] || col[j])
				matrix[i][j] = 0;
	}
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 56.17%
