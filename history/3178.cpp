#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int numberOfChild(int n, int k) {
	int len = k % ((n - 1) * 2);
	if (len >= n - 1) return 2 * n - len - 2;
	return len;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 41.65%
