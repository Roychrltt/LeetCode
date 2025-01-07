#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int hIndex(std::vector<int>& c) {
	std::sort(c.begin(), c.end());
	int n = c.size() - 1;
	if (c[n--] == 0) return 0;
	int ans = 1;
	while (n >= 0 && c[n] > ans)
	{
		ans++;
		n--;
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
// memory beats 60.65%
