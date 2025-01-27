#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int countPartitions(vector<int>& nums) {
	int n = nums.size();
	vector<int> preSum(n + 1);
	for (int i = 0; i < n; i++)
	{
		preSum[i + 1] = preSum[i] + nums[i];
	}
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (abs(preSum[i + 1] - preSum[n] + preSum[i + 1]) % 2 == 0)
			count++;
	}
	return count;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
