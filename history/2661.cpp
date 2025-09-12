#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
	int m = mat.size(), n = mat[0].size();
	std::vector<int> row(m, n), col(n, m);
	std::vector<std::pair<int, int>> pos(m * n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pos[mat[i][j] - 1].first = i;
			pos[mat[i][j] - 1].second = j;
		}
	}
	for (int i = 0; i < m * n; i++)
	{
		int x = arr[i] - 1;
		if (--row[pos[x].first] == 0) return i;
		if (--col[pos[x].second] == 0) return i;
	}
	return 0;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 95.12%
// memory beats 86.89%
