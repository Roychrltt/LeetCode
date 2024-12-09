#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	std::ranges::sort(nums, std::greater<>());
	long long prefix = 0, ans = 0;
	for (int i : nums) {
		prefix += i;
		if (prefix > 0)
			ans++;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {2,-1,0,1,-3,9,8};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 54.15%
// memory beats 89.39%
