#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

double f(double x, int n) {
	long long int N = n;
	if (N < 0)
	{
		x = 1/x;
		N = -N;
	}
	double ans = 1;
	while (N)
	{
		if (N & 1)
			ans *= x;
		x *= x;
		N >>= 1;
	}
	return ans;
}

int main()
{
	double x = 2.0000;
	int n = 30;
	double ans = f(x, n);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 10.90%
