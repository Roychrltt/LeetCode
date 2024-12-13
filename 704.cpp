#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		int x = (left + right) / 2;
		if (nums[x] > target)
			right = x - 1;
		else if (nums[x] < target)
			left = x + 1;
		else
			return x;
	}
	return nums[left] == target ? left : -1;
}

int main()
{
	std::vector<int> v = {-1,0,2,8,19,100};
	int ans = f(v,88);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 22.01%
