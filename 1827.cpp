#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	int count = 0;
	int prev = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] <= prev)
		{
			int d = prev - nums[i] + 1;
			count += d;
			nums[i] += d;
		}
		prev = nums[i];
	}
	return count;
}

int main()
{
	std::vector<int> v = {1,1,1};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 98.35%
// memory beats 6.72%
