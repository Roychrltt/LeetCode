#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

void rotate(vector<int>& nums, int k) {
	k %= nums.size();
	ranges::reverse(nums);
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 56.36%
