#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int missingNumber(std::vector<int>& nums) {
	int ans = nums.size();
	for (int i = 0; i < nums.size(); i++)
		ans += i - nums[i];
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 8.66%
