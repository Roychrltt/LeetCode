#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxAbsoluteSum(vector<int>& nums) {
	int minSum = 0;
	int maxSum = 0;
	int minCur = 0;
	int maxCur = 0;
	for (int x : nums)
	{
		minCur = std::min(minCur, 0) + x;
		minSum = std::min(minSum, minCur);
		maxCur = std::max(maxCur, 0) + x;
		maxSum = std::max(maxSum, maxCur);
	}
	return std::max(std::abs(minSum), maxSum);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 12.10%
