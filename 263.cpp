#include <bits/stdc++.h>

bool isUgly(int n) {
	if (n <= 0) return false;
	array<int, 3> arr= {2, 3, 5};
	for (int i : arr)
	{
		while (n % i == 0)
			n /= i;
	}
	return n == 1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 45.78%
