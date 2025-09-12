#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
	int total(std::vector<int>& nums, int start, int end)
	{
		if (start == end)
			return nums[start];
		int beginScore = nums[start] - total(nums, start + 1, end);
		int endScore = nums[end] - total(nums, start, end - 1);
		return std::max(beginScore, endScore);
	}
	public:
	bool predictTheWinner(vector<int>& nums) {
		int n = nums.size();
		return total(nums, 0, n - 1) >= 0;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 21.41%
// memory beats 43.84%
