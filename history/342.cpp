#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool isPowerOfFour(int n) {
	if (n <= 0 || __builtin_popcount(n) != 1) return false;
	int count = 0;
	while (n > 0)
	{
		n >>= 1;
		count++;
	}
	return count % 2;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 16.92%
