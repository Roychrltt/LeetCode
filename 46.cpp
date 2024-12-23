#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
	std::vector<std::vector<int>> ans;
	std::sort(nums.begin(), nums.end());
	ans.push_back(nums);
	while (std::next_permutation(nums.begin(), nums.end()))
	{
		ans.push_back(nums);
	}
	return ans;
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
	int n = nums.size();
	std::vector<std::vector<int>> ans;
	std::vector<int> set(n), halfSet(n);
	auto dfs = [&](this auto&& dfs, int i)
	{
		if (i == n)
		{
			ans.emplace_back(set);
			return;
		}
		for (int j = 0; j < n; j++)
		{
			if (!halfSet[j])
			{
				set[i] = nums[j];
				halfSet[j] = 1;
				dfs(i + 1);
				halfSet[j] = 0;
			}
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
// memory beats 50.99%
