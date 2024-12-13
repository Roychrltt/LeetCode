#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int k) {
	std::sort(nums.begin(), nums.end());
	int ans = 1, prev = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] - prev > k)
		{
			prev = nums[i];
			ans++;
		}
	}
	return ans;
}

int main()
{
	std::vector<int> v = {1,1,1,2,3,6,7,8};
	int ans = f(v, 2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 79.65%
// memory beats 87.43%
