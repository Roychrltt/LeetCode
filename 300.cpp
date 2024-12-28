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

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 54.27%
