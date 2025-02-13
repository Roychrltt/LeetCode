#include <bits/stdc++.h>

long long countBadPairs(vector<int>& nums) {
	unordered_map<int, int> map;
	long long count = 0, n = nums.size();

	for (int i = 0; i < n; i++) {
		int x = nums[i] - i;
		count += map[x];
		map[x]++;
	}

	return (n * (n - 1)) / 2 - count;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 70.06%
// memory beats 84.79%
