#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int> prefix(n), suffix(n);
	prefix[0] = nums[0];
	suffix[n - 1] = nums[n - 1];
	for (int i = 1; i < n; i++)
		prefix[i] = prefix[i - 1] * nums[i];

	for (int i = n - 2; i >= 0; i--)
		suffix[i] = suffix[i + 1] * nums[i];

	vector<int> ans(n);
	ans[0] = suffix[1];
	ans[n - 1] = prefix[n - 2];
	for (int i = 1; i < n - 1; i++) 
	{
		ans[i] = prefix[i - 1] * suffix[i + 1];
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
// memory beats 12.98%
