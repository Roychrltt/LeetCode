#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

void f(std::vector<int>& nums) {
	int n = nums.size(), i = n - 2;
	while (i >= 0 && nums[i] >= nums[i + 1])
		i--;
	if (i >= 0)
	{
		int j = n - 1;
		while (nums[j] <= nums[i])
			j--;
		std::swap(nums[i], nums[j]);
	}
	std::reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
	std::vector<int> v = {1,1,5};
	f(v);
	for (auto i : v)
		std::cout << i << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 17.74%
