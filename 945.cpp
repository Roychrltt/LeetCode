#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	std::ranges::sort(nums);
	int count = 0;
	for (size_t i = 1; i < nums.size(); i++)
	{
		if (nums[i] <= nums[i - 1])
		{
			count += nums[i - 1] - nums[i] + 1;
			nums[i] = nums[i - 1] + 1;
		}
	}
	return count;
}

int main()
{
	std::vector<int> v = {3,2,1,2,1,7};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 69.61%
// memory beats 31.63%
