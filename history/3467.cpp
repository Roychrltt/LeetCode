#include <bits/stdc++.h>

vector<int> transformArray(vector<int>& nums) {
	int count = 0;
	int n = nums.size();
	for (int x : nums)
		if (x & 1) count++;
	vector<int> v(n);
	for (int i = n - count; i < n; i++)
		v[i] = 1;
	return v;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 90.57%
