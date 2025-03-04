#include <bits/stdc++.h>

int minCost(vector<int>& nums) {
	int n = nums.size();
	vector<int> v;
	if (n % 2)
		v = nums;
	else
	{
		v.resize(n);
		for (int i = 0; i < n; i++)
			v[i] = max(nums[i], nums[n - 1]);
	}
	for (int i = n - 3 + n % 2; i > 0; i -= 2)
	{
		int b = nums[i], c = nums[i + 1];
		for (int j = 0; j < i; j++)
		{
			int a = nums[j];
			v[j] = min({v[j] + max(b, c), v[i] + max(a, c), v[i + 1] + max(a, b)});
		}
	}
	return v[0];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 96.83%
// memory beats 99.40%
