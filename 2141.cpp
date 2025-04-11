#include <bits/stdc++.h>

long long maxRunTime(int n, vector<int>& v) {
	long long sum = 0;
	for (int i : v) sum += i;
	long long l = 1, r = sum / n;

	while (l < r)
	{
		long long mid = r - (r - l) / 2;
		long long e = 0;

		for (int i : v) e += min((long long)i, mid);

		if (e >= mid * n) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 92.88%
// memory beats 86.38%
