#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
	std::vector<std::vector<int>> ans;
	std::sort(nums.begin(), nums.end());
	std::vector<int> v;
	for (int i = 0; i < nums.size(); i++)
	{
		v.push_back(nums[i]);
	}
	ans.push_back(v);
	while (std::next_permutation(v.begin(), v.end()))
	{
		ans.push_back(v);
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
