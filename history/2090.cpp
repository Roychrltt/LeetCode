#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> f(std::vector<int>& nums, int k) {
	long long sum = 0, n = nums.size();
	std::vector<int> ans(n);
	for (int i = 0; i < n && i < k * 2 + 1; i++)
		sum += nums[i];
	for (int i = 0; i < n && i < k; i++)
		ans[i] = -1;
	if (n < k + 1)
		return ans;
	ans[k] = sum / (k * 2 + 1);
	int l = 0;
	for (int i = k + 1; i < n - k; i++)
	{
		sum += nums[i + k] - nums[l++];
		ans[i] = sum / (k * 2 + 1);
	}
	for (int i = n - k; i < n; i++)
		ans[i] = -1;
	return ans;
}

int main()
{
	std::vector<int> v = {1,11,17,21,29};
	std::vector<int> ans = f(v, 4);
	std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}
// runtime beats 100%
// memory beats 42.21%
