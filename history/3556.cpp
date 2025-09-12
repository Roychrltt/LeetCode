#include <bits/stdc++.h>

long long sumOfLargestPrimes(string s) {
	auto isprime = [&](long long x)
	{
		if (x < 2) return false;
		for (long long i = 2; i * i <= x; i++)
			if (x % i == 0) return false;
		return true;
	};
	set<long long> set;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i; j < s.length(); j++)
		{
			long long x = stoll(s.substr(i, j - i + 1));
			if (isprime(x)) set.insert(x);
		}
	}
	long long sum = 0;
	vector<long long> v(set.begin(), set.end());
	int cnt = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		sum += v[i];
		if (++cnt >= 3) break;
	}
	return sum;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
