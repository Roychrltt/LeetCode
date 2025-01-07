#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	int n = nums.size();
	int l = 0;
	while (nums[l] <= target / 2)
	{
		int r = std::upper_bound(nums.begin(), nums.end(), target - nums[l]) - nums.begin() - 1;
		if (nums[r] + nums[l] == target) return {l + 1, r + 1};
		l++;
	}
	return {};
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 71.23%
