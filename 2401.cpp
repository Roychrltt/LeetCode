#include <bits/stdc++.h>

int longestNiceSubarray(vector<int>& nums) {
	int ans = 1;
	int comp = 0;
	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		int x = nums[i];

		while (comp & x) {
			count--;
			comp ^= nums[i - count - 1];
		}
		comp |= x;
		count++;

		ans = max(ans, count);
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
// runtime beats %
// memory beats %
