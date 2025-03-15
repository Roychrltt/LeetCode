#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>

int f(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int prev = nums[0];
        int cur = std::max(nums[0], nums[1]);
        int ans = cur;
        for (int i = 2; i < n; i++)
        {
            ans = std::max(cur, nums[i] + prev);
            prev = cur;
            cur = ans;
        }
        return ans;
    }

int main()
{
	std::vector<int> v = {1,1,100,1,2,100,2};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 89.63%
