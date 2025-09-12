#include <bits/stdc++.h>

long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
	int n = nums.size();
	unordered_map<int, int> cnt;
	long long res = 0;
	int prefix = 0;
	cnt[0] = 1;
	for (int i = 0; i < n; i++) {
		prefix += nums[i] % modulo == k;
		res += cnt[(prefix - k + modulo) % modulo];
		cnt[prefix % modulo]++;
	}
	return res;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 72.77%
// memory beats 59.16%
