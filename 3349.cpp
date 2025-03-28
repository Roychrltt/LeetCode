#include <bits/stdc++.h>

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
	int n = nums.size();
	if (k == 1) return true;
	int prevCount = 0;
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		if (nums[i] <= nums[i - 1])
		{
			prevCount = count;
			count = 1;
			continue;
		}
		count++;
		if (count == 2 * k || count == k && prevCount >= k) return true;
	}
	return false;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 94.20%
// memory beats 77.73%
