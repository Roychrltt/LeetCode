#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> map;
	map[0] = -1;
	int sum = 0, end = -1;
	int ans = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		if (map.count(sum - target))
		{
			if (map[sum - target] + 1 > end)
			{
				ans++;
				end = i;
			}
		}
		map[sum] = i;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {-1,3,5,1,4,2,-9,15};
	int ans = f(v, 6);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 96.42%
// memory beats 45.43%
