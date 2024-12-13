#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int x = (left + right) / 2;
		if (nums[x] > target)
			right = x - 1;
		else if (nums[x] < target)
			left = x + 1;
		else
			return x;
	}
	return left;
}

int main()
{
	std::vector<int> v = {1,2,3,5,6};
	int ans = f(v,7);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 10.15%
