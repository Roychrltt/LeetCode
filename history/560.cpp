#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int k) {
	int n = nums.size();
	std::vector<int> s(n + 1);
	for (int i = 0; i < n; i++)
		s[i + 1] = s[i] + nums[i];

	int ans = 0;
	std::unordered_map<int, int> map;
	for (int x : s)
	{
		ans += map.contains(x - k) ? map[x - k] : 0;
		map[x]++;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {-1,2,4,3,5,-5,-3,0,9};
	int ans = f(v,8);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 85.61%
// memory beats 37.39%
