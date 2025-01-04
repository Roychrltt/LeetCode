#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int waysToSplitArray(std::vector<int>& nums) {
	//long long total = std::reduce(nums.begin(), nums.end(), 0LL);
	long long total = 0;
	for (long long n : nums)
		total += n;
	long long sum = 0;
	int count = 0;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		sum += nums[i];
		if (total - sum <= sum) count++;
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
// runtime beats 100%
// memory beats 62.32%
