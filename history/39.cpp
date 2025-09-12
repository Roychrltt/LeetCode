#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
	std::ranges::sort(candidates);
	std::vector<std::vector<int>> ans;
	std::vector<int> set;
	int n = candidates.size();

	auto dfs = [&](this auto&& dfs, int i, int rem) -> void {
		if (rem == 0) {
			ans.push_back(set);
			return;
		}

		if (i == n || rem < candidates[i]) return;

		dfs(i + 1, rem);

		set.push_back(candidates[i]);
		dfs(i, rem - candidates[i]);
		set.pop_back(); 
	};

	dfs(0, target);
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
// memory beats 31.63%
