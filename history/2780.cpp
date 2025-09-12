#include <bits/stdc++.h>

int minimumIndex(vector<int>& nums) {
	int n = nums.size();
	int dominant;
	int cnt = 0;
	for (int x : nums)
	{
		if (cnt == 0) dominant = x;
		cnt += (x == dominant) ? 1 : -1;
	}
	cnt = std::count(nums.begin(), nums.end(), dominant);
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		cur += (nums[i] == dominant);
		if (cur * 2 > i + 1 && (cnt - cur) * 2 > n - i - 1)
			return i;
	}
	return -1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 87.97%
// memory beats 93.78%
