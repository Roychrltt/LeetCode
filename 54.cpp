#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
	if (matrix.empty()) return {};
	int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
	std::vector<int> res;
	while (true) {
		for (int i = l; i <= r; i++)
			res.push_back(matrix[t][i]);
		if (++t > b)
			break;
		for (int i = t; i <= b; i++)
			res.push_back(matrix[i][r]);
		if (l > --r)
			break;
		for (int i = r; i >= l; i--)
			res.push_back(matrix[b][i]);
		if (t > --b)
			break;
		for (int i = b; i >= t; i--)
			res.push_back(matrix[i][l]);
		if (++l > r)
			break;
	}
	return res;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 40.89%
