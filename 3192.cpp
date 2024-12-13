#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	int ans = nums[0] ^ 1;
	for (int i = 1; i < nums.size(); i++) {
		ans += nums[i - 1] ^ nums[i];
	}
	return ans;
}

int main()
{
	std::vector<int> v = {0,1,1,0,1};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 14.60%
