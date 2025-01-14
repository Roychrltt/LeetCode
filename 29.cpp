#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int divide(int dividend, int divisor) {
	if (divisor == 1) return dividend;
	if (dividend == INT_MIN && divisor == -1) return INT_MAX;
	int ans = 0;
	bool sign = false;
	if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) sign = true;
	long long di = dividend == INT_MIN ? 2147483648 : std::abs(dividend);
	long long ds = divisor == INT_MIN ? 2147483648 : std::abs(divisor);
	while (di >= ds)
	{
		long long d = ds, count = 1;
		while (d <= di - d)
		{
			d <<= 1;
			count <<= 1;
		}
		di -= d;
		ans += count;
	}
	return sign ? -ans : ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 61.64%
