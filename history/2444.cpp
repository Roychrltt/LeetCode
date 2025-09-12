#include <bits/stdc++.h>

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
	long count = 0, start = -1, mini = -1, maxi = -1;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < minK || nums[i] > maxK) start = i;
		if (nums[i] == maxK) maxi = i;
		if (nums[i] == minK) mini = i;
		int valid = max(0L, min(mini, maxi) - start);
		count += valid;
	}
	return count;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 94.46%
