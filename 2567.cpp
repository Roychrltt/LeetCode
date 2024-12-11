#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& a) {
	std::ranges::sort(a);
	int n = a.size();
	return std::min({a[n - 3] - a[0], a[n - 2] - a[1], a[n - 1] - a[2]});
}

int main()
{
	std::vector<int> v = {1,3,90,100,1000};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 96.69%
// memory beats 62.66%
