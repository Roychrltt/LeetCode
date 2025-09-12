#include <bits/stdc++.h>

int countGoodNumbers(long long n) {
	const int M = 1e9 + 7;
	auto fastEx = [&](int k, long long len) -> int
	{
		int ans = 1, exp = k;
		while (len)
		{
			if (len & 1) ans = (long long)ans * exp % M;
			exp = (long long)exp * exp % M;
			len >>= 1;
		}
		return ans;
	};
	return (long long)fastEx(5, (n + 1) / 2) * fastEx(4, n / 2) % M;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 69.95%
