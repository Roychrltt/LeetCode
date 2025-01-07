#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int findMaxLength(std::vector<int>& nums) {
	std::unordered_map<int, int> map;
	map[0] = -1;
	int count = 0;
	int ans = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 1)
			count++;
		else
			count--;

		if (map.count(count))
			ans = std::max(ans, i - map[count]);
		else
			map[count] = i;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 58.27%
// memory beats 52.94%
