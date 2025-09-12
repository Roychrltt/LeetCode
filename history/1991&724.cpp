#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int findMiddleIndex(std::vector<int>& nums) {
	int n = nums.size();
	std::vector<int> v(n + 1);
	for (int i = 0; i < n; i++)
		v[i + 1] = v[i] + nums[i];
	for (int i = 1; i <= n; i++)
		if (v[n] - v[i] == v[i - 1]) return i - 1;

	return -1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 20.24%
