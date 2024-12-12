#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& g, std::vector<int>& s) {
	std::sort(g.begin(), g.end());
	std::sort(s.begin(), s.end());
	int i = 0;
	for (int x : s) {
		if (i < g.size() && g[i] <= x) {
			i++;
		}
	}
	return i;
}

int main()
{
	std::vector<int> v1 = {1,3,5,2,7,4,78};
	std::vector<int> v2 = {2,3,6,2,10,4,7};
	int ans = f(v1, v2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 54.31%
// memory beats 75.25%
