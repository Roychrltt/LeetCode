#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (nums[mid] == target)
			return mid;
		if (nums[left] <= nums[mid])
			(target >= nums[left] && target < nums[mid]) ? right = mid - 1 : left = mid + 1;
		else
			(target > nums[mid] && target <= nums[right]) ? left = mid + 1 : right = mid - 1;
	}
	return -1;
}

int main()
{
	std::vector<int> v = {7,8,9,1,2,3,4,5};
	int ans = f(v, 6);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 28.50%
