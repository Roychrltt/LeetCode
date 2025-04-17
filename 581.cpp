#include <bits/stdc++.h>

int findUnsortedSubarray(vector<int>& nums) {
	int l = 0, r = 0, n = nums.size();
	int max = nums[0], min = nums[n - 1];
	for (int i = 1; i < n; i++)
	{
		if (nums[i] > max)
			max = nums[i];
		if (nums[i] < max) 
			l = i;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if (nums[i] < min)
			min = nums[i];
		if (nums[i] > min)
			r = i;
	}
	if (r == 0 && l == 0) return 0;
	return abs(r - l) + 1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 92.62%
