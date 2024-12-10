#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	int a = INT_MAX, b = INT_MAX;
	for (int i = 1; i < nums.size(); i++) {
		int x = nums[i];
		if (x < a) {
			b = a;
			a = x;
		} else if (x < b) {
			b = x;
		}
	}
	return nums[0] + a + b;
}

int main()
{
	std::vector<int> v = {1,2,3,12};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 21.25%
