#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int k) {
        int res = 0;
		std::sort(nums.begin(), nums.end(), [](int a, int b ){
            return abs(a) > abs(b); 
        });
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 && k > 0)
                nums[i] = -nums[i], --k;
            res += nums[i]; 
        }
        if (k % 2) res -= (2 * nums[nums.size() - 1]);
        return res;
    }

int main()
{
	std::vector<int> v = {2,-3,-1,5,-4};
	int ans = f(v, 3);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 47.99%
