#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int findNumberOfLIS(vector<int>& nums) {
	int n = nums.size();
	std::vector<int> f(n, 1), g(n, 1);
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				if (f[i] < f[j] + 1)
				{
					f[i] = f[j] + 1;
					g[i] = g[j];
				}
				else if (f[i] == f[j] + 1)
					g[i] += g[j];
			}
		}
		c = std::max(c, f[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (f[i] == c)
			ans += g[i];
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 57.34%
// memory beats 44.27%
