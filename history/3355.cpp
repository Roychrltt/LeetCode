#include <bits/stdc++.h>

bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
	int n = nums.size();
	vector<int> dif(n + 1);
	dif[0] = nums[0];
	for (int i = 1; i < n; i++)
		dif[i] = nums[i] - nums[i - 1];

	for (auto& v : queries)
	{
		dif[v[0]]--;
		dif[v[1] + 1]++;
	}
	if (dif[0] > 0) return false;
	for (int i = 1; i < n; i++)
	{
		dif[i] += dif[i - 1];
		if (dif[i] > 0) return false;
	}
	return true;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 90.29%
// memory beats 74.53%
