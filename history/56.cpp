#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
{
	std::ranges::sort(intervals);
	std::vector<std::vector<int>>ans;

	for (auto& p : intervals)
	{
		if (!ans.empty() && p[0] <= ans.back()[1])
			ans.back()[1] = std::max(p[1], ans.back()[1]);
		else
			ans.emplace_back(p);
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
// runtime beats 91.04%
// memory beats 39.11%
