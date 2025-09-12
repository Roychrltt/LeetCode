#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> f(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> umap;
	size_t n = nums.size();
	umap.reserve(n);
	for (size_t i = 0; i < n; i++)
	{
		int comp = target - nums[i];
		if (umap.count(comp))
		{
			return {static_cast<int>(i), umap[comp]};
		}
		umap[nums[i]] = i;
	}
	return {};
}

int main()
{
	std::vector<int> v = {2,7,11,15};
	std::vector<int> ans = f(v, 9);
	for (auto i : ans)
		std::cout << i << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 24.77%
