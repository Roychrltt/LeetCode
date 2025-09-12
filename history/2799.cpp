#include <bits/stdc++.h>

int countCompleteSubarrays(vector<int>& nums) {
	vector<int> map(2002);
	int cnt = 0;
	for (int i : nums)
		if (map[i]++ == 0) cnt++;

	map.clear();
	map.resize(2002);
	int cur = 1;
	int sum = 0, l = 0, r = 1;
	map[nums[0]]++;
	if (cur == cnt) sum++;
	while (r < nums.size())
	{
		if (map[nums[r]]++ == 0) cur++;
		while (l < r && map[nums[l]] > 1)
			map[nums[l++]]--;
		if (cur == cnt) sum += l + 1;
		r++;
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
// runtime beats 100%
// memory beats 26.77%
