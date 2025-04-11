#include <bits/stdc++.h>

int firstMissingPositive(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++)
		if (nums[i] < 1) nums[i] = n + 1;

	for (int i = 0; i < n; i++)
	{
		int cur = abs(nums[i]);
		if (cur <= n && nums[cur - 1] > 0) nums[cur - 1] *= -1;
	}
	for (int i = 0; i < n; i++)
		if (nums[i] > 0) return i + 1;
	return n + 1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 62%
// memory beats 46%
