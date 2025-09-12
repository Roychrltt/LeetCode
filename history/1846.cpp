#include <iostream>
#include <algorithm>
#include <vector>

int f(std::vector<int>& nums) {
	std::ranges::sort(nums);
	nums[0] = 1;
	int n = nums.size();
	for (int i = 1; i < n; i++)
	{
		if (nums[i] > nums[i - 1] + 1)
			nums[i] = nums[i - 1] + 1;
	}
	return nums[n - 1];
}

int main(void)
{
	std::vector<int> v = {2,2,1,2,1};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}

// runtime beats 62.67%
// memory beats 70.48%
