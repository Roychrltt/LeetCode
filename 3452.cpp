#include <bits/stdc++.h>

int sumOfGoodNumbers(vector<int>& nums, int k) {
	int sum = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		if ((i - k >= 0 && nums[i] <= nums[i - k]) || (i + k < n && nums[i] <= nums[i + k]))
			continue;
		sum += nums[i];
	}
	return sum;
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
