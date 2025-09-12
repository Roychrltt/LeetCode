#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	//ranges::sort(nums);
	std::sort(nums.begin(), nums.end());
	for (int i = nums.size() - 1; i >= 2; i--) {
		if (nums[i - 2] + nums[i - 1] > nums[i]) {
			return nums[i - 2] + nums[i - 1] + nums[i];
		}
	}
	return 0;
}

int main()
{
	std::vector<int> v = {1,2,1,10};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 75.59%
// memory beats 91.54%
