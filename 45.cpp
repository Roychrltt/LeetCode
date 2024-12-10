#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	int n = nums.size();
	int count = 0, nextEnd = 0, maxJump = 0;

	for (int i = 0; i < n - 1; ++i) {
		maxJump = std::max(maxJump, i + nums[i]);
		if (i == nextEnd) {
			count++;
			nextEnd = maxJump;
		}
	}
	return count;
}

int main()
{
	std::vector<int> v = {2,3,1,1,4};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 84.83%
