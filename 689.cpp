#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> maxSumOfThreeSubarrays(std::vector<int>& nums, int k) {
	std::vector<int> ans;
	int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
	int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
	int sum3 = 0, maxTotal = 0;
	for (int i = k * 2; i < nums.size(); ++i) {
		sum1 += nums[i - k * 2];
		sum2 += nums[i - k];
		sum3 += nums[i];
		if (i >= k * 3 - 1) {
			if (sum1 > maxSum1) {
				maxSum1 = sum1;
				maxSum1Idx = i - k * 3 + 1;
			}
			if (maxSum1 + sum2 > maxSum12) {
				maxSum12 = maxSum1 + sum2;
				maxSum12Idx1 = maxSum1Idx;
				maxSum12Idx2 = i - k * 2 + 1;
			}
			if (maxSum12 + sum3 > maxTotal) {
				maxTotal = maxSum12 + sum3;
				ans = {maxSum12Idx1, maxSum12Idx2, i - k + 1};
			}
			sum1 -= nums[i - k * 3 + 1];
			sum2 -= nums[i - k * 2 + 1];
			sum3 -= nums[i - k + 1];
		}
	}
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
// memory beats 92.68%
