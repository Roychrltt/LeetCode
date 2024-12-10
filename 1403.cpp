#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> f(std::vector<int>& nums) {
        int total = std::reduce(nums.begin(), nums.end());
		std::sort(nums.begin(), nums.end());
		std::vector<int> ans;
        int cur = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            cur += nums[i];
            ans.emplace_back(nums[i]);
            if (total - cur < cur) {
                break;
            }
        }
        return ans;
    }

int main()
{
	std::vector<int> v = {4,3,10,9,8};
	std::vector<int> ans = f(v);
	for (auto num : ans) {
		std::cout << num << std::endl;
	}
	return 0;
}
// runtime beats 100%
// memory beats 43.07%
