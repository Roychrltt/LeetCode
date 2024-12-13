#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <climits>

int f(std::vector<int>& nums) {
	int c0 = 0, c1 = 0;
	for (int i = 0; i < nums.size(); i++) {
		int l = (i > 0) ? nums[i - 1] : INT_MAX;
		int r = (i + 1 < nums.size()) ? nums[i + 1] : INT_MAX;

		if ((i & 1) == 0) {
			c0 += std::max(0, nums[i] - std::min(l, r) + 1);
		} else {
			c1 += std::max(0, nums[i] - std::min(l, r) + 1);
		}
	}
	return std::min(c0, c1);
}

int main()
{
	std::vector<int> v = {2,7,10,9,8,9};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 6.15%
