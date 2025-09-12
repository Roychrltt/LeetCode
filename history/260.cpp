#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> singleNumber(std::vector<int>& nums) {
        int res = 0;
        for (int x: nums)
            res ^= x;
        int count = __builtin_ctz(res);
		std::vector<int> ans(2);
        for (int x: nums)
            ans[x >> count & 1] ^= x;
        
        return ans;
    }

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 56.94%
