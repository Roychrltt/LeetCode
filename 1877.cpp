#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	int n = nums.size();
	int ans = 0;
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		ans = std::max(ans, nums[i] + nums[j]);
	}
	return ans;
}

int main()
{
	std::vector<int> v = {3,5,2,5,9,2,1,6,8,7};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 78.97%
// memory beats 92.13%
