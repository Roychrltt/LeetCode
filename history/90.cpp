#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> f(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	std::set<std::vector<int>> ans;
	std::vector<int> set;
	int n = nums.size();
	auto dfs = [&](this auto&& dfs, int i) -> void {
		ans.insert(set);
		for (int j = i; j < n; j++) {
			set.push_back(nums[j]);
			dfs(j + 1);
			set.pop_back();
		}
	};
	dfs(0);
	std::vector<std::vector<int>> res;
	res.assign(ans.begin(), ans.end());
	return res;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 37.51%
