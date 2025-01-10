#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> generate(int n) {
	std::vector<std::vector<int>> ans(n);
	for (int i = 0; i < n; i++)
	{
		std::vector<int> v(i + 1, 1);
		for (int j = 1; j < i; j++)
			v[j] = ans[i - 1][j - 1] + ans[i - 1][j];
		ans[i] = std::move(v);
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
// runtime beats %
// memory beats 49.85%
