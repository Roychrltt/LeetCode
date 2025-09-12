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
	std::vector<int> set(n), visited(n);
	auto dfs = [&](this auto&& dfs, int i)
	{
		if (i == n)
		{
			ans.emplace_back(set);
			return;
		}
		for (int j = 0; j < n; j++)
		{
			if (!visited[j])
			{
				set[i] = nums[j];
				visited[j] = 1;
				dfs(i + 1);
				visited[j] = 0;
			}
		}
	};
	dfs(0);
	return ans;
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
	std::vector<std::vector<int>> ans = {{}};

	for (int num : nums)
	{
		std::vector<std::vector<int>> newAns;
		for (auto& perm : ans)
		{
			for (size_t i = 0; i <= perm.size(); ++i)
			{
				std::vector<int> newPerm = perm;
				newPerm.insert(newPerm.begin() + i, num);
				newAns.push_back(newPerm);
			}
		}
		ans = std::move(newAns);
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
// memory beats 50.99%
