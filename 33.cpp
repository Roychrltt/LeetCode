#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int x = (left + right) / 2;
		if ((nums[0] > target) ^ (nums[0] > nums[x]) ^ (target > nums[x]))
			left = x + 1;
		else
			right = x;
	}
	return left == right && nums[left] == target ? left : -1;
}

int main()
{
	std::vector<int> v = {7,8,9,1,2,3,4,5};
	int ans = f(v, 6);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 17.72%
