#include <bits/stdc++.h>

long long countGood(vector<int>& nums, int k) {
	unordered_map<int, int> map;
	long long ans = 0;
	int n = nums.size(), same = 0;
	if (n == 1) return k == 0;
	int l = 0, r = 1;
	map[nums[0]]++;
	map[nums[1]]++;
	if (nums[0] == nums[1]) same++;
	while (l < n)
	{
		while (same < k && r < n)
		{
			r++;
			same += map[nums[r]];
			map[nums[r]]++;
		}
		if (same >= k) ans += n - r;
		map[nums[l]]--;
		same -= map[nums[l]];
		l++;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 60.43%
// memory beats 77.96%
