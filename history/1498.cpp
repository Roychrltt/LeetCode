#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

long long int fastPower(long long int x, long long int p)
{
	long long int res = 1;
	while (p)
	{
		if (p & 1) res = (res * x) % MOD;
		p >>= 1;
		x = (x * x) % MOD;
	}
	return res;
}

int f(std::vector<int>& nums, int target)
{
	int n = nums.size();
	sort(nums.begin(), nums.end());

	int l = 0, r = n - 1, ans = 0;

	while (l <= r)
	{
		if (nums[l] + nums[r] <= target)
		{
			ans = (ans + fastPower(2, r - l)) % MOD;
			l++;
		}
		else r--;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {2,3,3,4,6,7};
	int ans = f(v, 12);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
