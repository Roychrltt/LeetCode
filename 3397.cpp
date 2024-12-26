#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxDistinctElements(vector<int>& nums, int k) {
	int n = nums.size();
	if (k * 2 + 1 >= n)
		return n;
	std::ranges::sort(nums);
	int count = 0;
	int prev = std::numeric_limits<int>::min();
	for (int x : nums)
	{
		x = std::clamp(prev + 1, x - k, x + k);
		if (x > prev)
		{
			count++;
			prev = x;
		}
	}
	return count;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 98.15%
// memory beats 84.38%
