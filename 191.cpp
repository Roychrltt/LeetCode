#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(int n) {
	int ans = 0;
	while (n)
	{
		if ((n & 1) == 1)
			ans++;
		n >>= 1;
	}
	return ans;
}

int main()
{
	int ans = f(21);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 32.82%
