#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

double findMaxAverage(vector<int>& nums, int k) {
	int curSum = 0, maxSum = 0;
	for (int i = 0; i < k; i++)
		curSum += nums[i];
	maxSum = curSum;
	for (int i = k; i < nums.size(); i++)
	{
		curSum += nums[i] - nums[i - k];
		maxSum = std::max(maxSum, curSum);
	}
	return (double)maxSum / k;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 26.40%
