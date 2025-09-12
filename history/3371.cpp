#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	int n = nums.size();
	int sum = 0;
	std::unordered_map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		map[nums[i]]++;
		sum += nums[i];
	}
	int ans = -1000;
	for (int i = 0; i < n; ++i)
	{
		int outlier = sum - nums[i] * 2;
		if (map[outlier] > 1 || (map[outlier] == 1 && sum != outlier * 3))
			ans = std::max(outlier, ans);
	}
	return ans;
}

int main()
{
	std::vector<int> v= {6,-31,50,-35,41,37,-42,13};
	int ans = f(v);
	std::vector<int> v1= {5,1,1,1,1,1,5};
	int ans2 = f(v1);
	std::cout << ans << std::endl;
	std::cout << ans2 << std::endl;
	return 0;
}
// runtime beats 99.42%
// memory beats 44.70%
