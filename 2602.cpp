#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<long long> f(std::vector<int>& nums, std::vector<int>& queries) {
	int n = nums.size();
	int m = queries.size();
	std::sort(nums.begin(), nums.end());
	std::vector<long long> ans(m);
	std::vector<long long> sum(n + 1);
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + nums[i];

	for (int i = 0; i < m; i++)
	{
		int q = queries[i];
		long long j = std::ranges::lower_bound(nums, q) - nums.begin();
		long long left = q * j - sum[j];
		long long right = sum[n] - sum[j] - q * (n - j);
		ans[i] = left + right;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {1,2,3,4,5};
	std::vector<int> v1 = {10,20,30,40,50};
	std::vector<long long> ans = f(v, v1);
	for (auto i : ans)
		std::cout << i << std::endl;
	return 0;
}
// runtime beats 71.72%
// memory beats 87.19%
