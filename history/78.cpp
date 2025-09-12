#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

vector<vector<int>> subsets(vector<int>& nums) {
	std::vector<std::vector<int>> ans;
	std::vector<int> set;
	int n = nums.size();
	auto dfs = [&](this auto&& dfs, int i) -> void
	{
		ans.emplace_back(set);
		for (int j = i; j < n; j++)
		{
			set.push_back(nums[j]);
			dfs(j + 1);
			set.pop_back();
		}
	};
	dfs(0);
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
// memory beats 58.94%
