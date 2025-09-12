#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> grayCode(int n) {
	std::vector<int> ans;
	ans.push_back(0);

	int head = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = ans.size() - 1; j >= 0; j--)
			ans.push_back(head + ans[j]);
		head <<= 1;
	}
	return ans;
}

std::vector<int> grayCode(int n) {
	std::vector<int> ans;

	int total = 1 << n;
	for (int i = 0; i < total; i++)
	{
		int gray = i ^ (i >> 1);
		ans.push_back(gray);
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
// runtime beats 100%
// memory beats 53.11%
