#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minimumOperations(vector<int>& nums) {
	int count = 0;
	int n = nums.size();
	std::unordered_map<int, int> map;
	for (int i = n - 1; i >= 0; i--)
	{
		if (map.count(nums[i]) > 0)
			break;
		map[nums[i]] = nums[i];
		count++;
	}
	return (n - count + 2) / 3;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 75.89%
// memory beats 87.66%
