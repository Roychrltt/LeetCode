#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	int size = nums.size();
	if (size < 5)
		return 0;

	sort(nums.begin(), nums.end());
	int res = INT_MAX;
	res = std::min(res, nums[size - 4] - nums[0]);
	res = std::min(res, nums[size - 3] - nums[1]);
	res = std::min(res, nums[size - 2] - nums[2]);
	res = std::min(res, nums[size - 1] - nums[3]);
	return res;
}

int main()
{
	std::vector<int> v = {1,5,0,10,14};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 72.33%
// memory beats 75.40%
