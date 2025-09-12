#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxSubArray(vector<int>& nums) {
	// DP
	/*
	   	int ans = std::numeric_limits<int>::min();
	   	int temp = 0;
	   	for (int x : nums)
	   	{
	   		temp = std::max(temp, 0) + x;
	   		ans = std::max(ans, temp);
	   	}
	   */
	// Kadane's algo
	/*
	 	int ans = nums[0];
        int maxEnding = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            maxEnding = max(maxEnding + nums[i], nums[i]);
            ans = max(maxEnding, ans);
        }
        return ans;
	 */
	int ans = INT_MIN;
	int minPresum = 0;
	int presum = 0;
	for (int x : nums) {
		presum += x;
		ans = max(ans, presum - minPresum);
		minPresum = min(minPresum, presum);
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
std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
// runtime beats 100%
// memory beats 21.53%
