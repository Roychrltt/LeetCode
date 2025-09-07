#include <bits/stdc++.h>

std::vector<int> f(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
	int n = nums.size();
	std::vector<int> dp(n, 1), prev(n, -1);
	int mx = -1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
		if (dp[i] > dp[mx]) mx = i;
	}
	std::vector<int> ans;
	for (int i = mx; i >= 0; i = prev[i])
		ans.push_back(nums[i]);
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
