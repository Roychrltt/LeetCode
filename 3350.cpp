#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")

int maxIncreasingSubarrays(vector<int>& nums) {
	int n = nums.size();
	int prev = 0;
	int count = 1;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (nums[i] <= nums[i - 1]) {
			ans = max(ans, min(prev, count));
			prev = count;
			count = 1;
			continue;
		}
		count++;
		ans = max(ans, count / 2);
	}
	ans = max(ans, min(prev, count));
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 93.99%
// memory beats 82.46%
