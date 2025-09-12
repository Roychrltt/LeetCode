#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int lengthOfLIS(vector<int>& nums) {
	std::vector<int> v;
	for (int x : nums)
	{
		auto it = lower_bound(v.begin(), v.end(), x);
		if (it == v.end())
			v.push_back(x);
		else
			*it = x;
	}
	return v.size();
}

// DP
int lengthOfLIS(std::vector<int>& nums) {
	int n = nums.size();
	std::vector<int> v(n, 1);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
				if (v[i] < v[j] + 1)
					v[i] = v[j] + 1;
		}
		ans = std::max(v[i], ans);
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
// memory beats 54.27%
