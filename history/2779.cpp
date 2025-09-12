#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int k) {
	std::sort(nums.begin(), nums.end());
	int j = 0, ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		while (nums[j] + k < nums[i] - k)
			j++;
		ans = std::max(i - j + 1, ans);
	}
	return ans;
}

int main()
{
	std::vector<int> v = {4,6,1,2};
	int ans = f(v, 2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 86.10%
// memory beats 84.24%
