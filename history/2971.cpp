#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>

long long f(std::vector<int>& nums)
{
	std::ranges::sort(nums);
	long long sum = std::reduce(nums.begin(), nums.end(), 0LL);
	size_t n = nums.size();
	for (size_t i = n - 1; i > 1; --i)
	{
		int x = nums[i];
		if (sum > x * 2)
			return sum;
		sum -= x;
	}
	return -1;
}

int main()
{
	std::vector<int> v = {1,33,25,42,12,2,20,14,4,22};
	long long int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 71.57%
// memory beats 89.75%
