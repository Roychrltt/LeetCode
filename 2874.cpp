#include <bits/stdc++.h>

long long maximumTripletValue(vector<int>& nums) {
	int n = nums.size();
	vector<int> leftMax(n), rightMax(n);
	for (int i = 1; i < n; i++) {
		leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
		rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
	}
	long long res = 0;
	for (int j = 1; j < n - 1; j++) {
		res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
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
// runtime beats 73.82%
// memory beats 42.06%
