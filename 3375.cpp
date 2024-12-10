#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int k) {
	std::sort(nums.begin(), nums.end());
	if (nums[0] < k)
		return -1;
	int prev = nums[0];
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == prev && i != 0)
			continue;
		prev = nums[i];
		if (nums[i] > k)
			count++;
	}
	return count;
}

int main()
{
	std::vector<int> v = {5,2,5,4,5};
	int ans = f(v, 2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 80.19%
// memory beats 80.09%
