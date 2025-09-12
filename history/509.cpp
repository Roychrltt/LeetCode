#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int fib(int n) {
	int zero = 0, one = 1;
	if (n < 2) return n;;
	for (int i = 2; i <= n; i++)
	{
		int tmp = one;
		one = zero + one;
		zero = tmp;
	}
	return one;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 77.80%
// memory beats 72.22%
