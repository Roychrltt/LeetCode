#include <bits/stdc++.h>

long long countSubarrays(vector<int>& nums, int k) {
	int x = *max_element(nums.begin(), nums.end());
	long long ans = 0, cnt = 0;
	for (int l = 0, j = 0; j < nums.size(); j++)
	{
		if (nums[j] == x) cnt++;
		while (cnt >= k)
		{
			if (cnt == k && nums[l] == x)
			{
				ans += l + 1;
				break;
			}
			if (nums[l] == x) cnt--;
			l++;
		}            
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
// runtime beats 100%
// memory beats 74.24%
