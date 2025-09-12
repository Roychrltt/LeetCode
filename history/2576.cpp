#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	int i = 0, n = nums.size();
	for (int j = (n + 1) / 2; j < n; j++) {
		if (nums[i] * 2 <= nums[j])
			i++;
	}
	return i * 2;
}

int main()
{
	std::vector<int> v = {3,5,2,7,5,6,1,1,8,7,7,8,8,8,9,3};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 86.43%
// memory beats 82.11%
