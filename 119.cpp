#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

vector<int> getRow(int n) {
	std::vector<std::vector<int>> ans(n + 1);
	for (int i = 0; i < n + 1; i++) {
		std::vector<int> v(i + 1, 1);
		for (int j = 1; j < i; j++)
			v[j] = ans[i - 1][j - 1] + ans[i - 1][j];
		ans[i] = std::move(v);
	}
	return ans[n];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 11.47%
