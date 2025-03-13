#include <bits/stdc++.h>

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
	int n = nums.size();
	auto check = [&](this auto&& check, int k) -> bool {
		vector<int> diff(n + 1, 0);
		for (int i = 0; i < k; i++) {
			diff[queries[i][0]] -= queries[i][2];
			diff[queries[i][1] + 1] += queries[i][2];
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) diff[i] += diff[i - 1];
			if (nums[i] + diff[i] > 0)
				return false;
		}
		return true;
	};
	int left = 0, right = queries.size();

	if (!check(right)) return -1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (check(mid)) right = mid;
		else left = mid + 1;
	}
	return right;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 64.29%
// memory beats 61.50%
