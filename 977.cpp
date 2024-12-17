#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> f(std::vector<int>& nums) {
	int n = nums.size();
	std::vector<int> ans(n);
	int i = 0, j = n - 1;
	for (int p = n - 1; p >= 0; p--) {
		int x = nums[i] * nums[i];
		int y = nums[j] * nums[j];
		if (x > y) {
			ans[p] = x;
			i++;
		} else {
			ans[p] = y;
			j--;
		}
	}
	return ans;
}

int main()
{
	std::vector<int> v = {-4, -3, -1, 0, 2, 5};
	std::vector<int> ans = f(v);
	std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}
// runtime beats 100%
// memory beats 45.13%
