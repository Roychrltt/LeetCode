#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
	int m = mat.size(), n = mat[0].size();
	std::vector<int> ans;
	int i = 0, j = 0;
	int dh = 1, dv = -1;
	while (i < m - 1 || j < n - 1)
	{
		while (i < m && i >= 0 && j < n && j >= 0)
		{
			ans.push_back(mat[i][j]);
			i += dv;
			j += dh;
		}
		i -= dv;
		j -= dh;
		if ((i == 0 || i == m - 1) && j < n - 1) j++;
		else if ((j == 0 || j == n - 1) && i < m - 1) i++;
		dh = -dh;
		dv = -dv;
	}
	ans.push_back(mat[m - 1][n - 1]);
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
// memory beats 44.00%
