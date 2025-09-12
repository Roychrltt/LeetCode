#include <bits/stdc++.h>

bool checkPowersOfThree(int n) {
	while (n)
	{
		if (n % 3 == 2) return false;
		n /= 3;
	}
	return true;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 91.08%
