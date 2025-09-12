#include <bits/stdc++.h>

int minSwaps(vector<int>& nums) {
	int n = nums.size();
	int cnt = 0;
	for (int i : nums)
		if (i & 1) cnt++;
	auto f = [&](int d) -> int
	{
		int ans = 0;
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] & 1)
			{
				ans += abs(j * 2 + d - i);
				j++;
			}
		}
		return ans;
	};
	if (n % 2 == 0)
	{
		if (cnt != n / 2) return -1;
		return min(f(0), f(1));
	}
	else
	{
		if (cnt != n / 2 && cnt != n / 2 + 1) return -1;
		if (cnt == n / 2) return f(1);
		else return f(0);
	}
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
