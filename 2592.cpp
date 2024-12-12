#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	int i = 0;
	for (int x : nums)
		if (x > nums[i])
			++i;
	return i;
}

int main()
{
	std::vector<int> v = {1,2,2,3,3,3,4,5,6,7};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 91.92%
// memory beats 56.34%
