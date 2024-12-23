#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

void sortColors(std::vector<int>& nums) {
	int n = nums.size();
	int l = 0, r = n - 1;
	for (int i = 0; i <= r; ++i) {
		while (i <= r && nums[i] == 2)
			std::swap(nums[i], nums[r--]);
		if (nums[i] == 0)
			std::swap(nums[i], nums[l++]);
	}       
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 28.63%
