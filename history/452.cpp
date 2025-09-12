#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<std::vector<int>>& points) {
	std::ranges::sort(points, {}, [](auto& p) { return p[1]; }); 
	int count = 0;
	long long end = LLONG_MIN;
	for (auto& p : points)
	{
		if (p[0] > end)
		{
			count++;
			end = p[1];
		}
	}
	return count;
}

int main()
{
	std::vector<std::vector<int>> v = {{10,16}, {2,8}, {1,6}, {7,12}};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 90.70%
// memory beats 39.29%
