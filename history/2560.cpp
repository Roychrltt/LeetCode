#include <bits/stdc++.h>

int minCapability(vector<int>& nums, int k) {
	int n = nums.size();
	int left = *min_element(nums.begin(), nums.end()), right = *max_element(nums.begin(), nums.end());
	auto check = [&](int x) -> bool
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] <= x)
			{
				if (++count >= k) return true;
				i++;
			}
		}
		return false;
	};
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (check(mid))
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 95.45%
// memory beats 94.16%
