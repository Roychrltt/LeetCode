#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int rob1(vector<int> &nums, int start, int end) { 
	int f0 = 0, f1 = 0;
	for (int i = start; i < end; i++) {
		int new_f = max(f1, f0 + nums[i]);
		f0 = f1;
		f1 = new_f;
	}
	return f1;
}

int rob(vector<int> &nums) {
	int n = nums.size();
	return max(nums[0] + rob1(nums, 2, n - 1), rob1(nums, 1, n));
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 38.85%
