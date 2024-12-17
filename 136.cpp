#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	int ans = 0;
	for (auto x : nums)
		ans ^= x;
	return ans;
}

int main()
{
	std::vector<int> v = {1,1,2,2,4,4,3,5,5};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 33.51%
