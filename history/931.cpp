#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minFallingPathSum(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cur = std::numeric_limits<int>::max();
			for (int k = std::max(0, j - 1); k < std::min(n, j + 2); k++)
				cur = std::min(cur, matrix[i - 1][k]);
			matrix[i][j] += cur;
		}
	}
	return *min_element(matrix[m - 1].begin(), matrix[m - 1].end());
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 46.69%
