#include <bits/stdc++.h>

int maximumCount(vector<int>& nums) {
	auto it1 = upper_bound(nums.begin(), nums.end(), -1);
	auto it2 = lower_bound(nums.begin(), nums.end(), 1);
	int a = it1 - nums.begin();
	int b = it2 - nums.begin();
	return max(a, (int)nums.size() - b);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 43.55%
