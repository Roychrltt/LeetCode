#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxSubArray(vector<int>& nums) {
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
// runtime beats 100%
// memory beats 21.53%
