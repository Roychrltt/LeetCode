#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool isPowerOfTwo(int n) {
	return (n > 0 && __builtin_popcount(n) == 1);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 85.13%
