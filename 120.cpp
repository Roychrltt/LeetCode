#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minimumTotal(std::vector<std::vector<int>>& triangle) {
	int n = triangle.size();
	std::vector<std::vector<int>> f(n, std::vector<int>(n));
	f[n - 1] = triangle[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return f[0][0];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 13.95%
