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

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 46.99%
