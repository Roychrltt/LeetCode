#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(int X, int Y) {
	int res = 0;
	while (Y > X)
	{
		if (Y % 2 == 1)
			++Y;
		else
			Y /= 2;
		++res;
	}

	return res + X - Y;
}

int main()
{
	int a = 10, b = 991;
	int ans = f(a, b);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 9.38%
