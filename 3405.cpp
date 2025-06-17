#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
const int MX = 1e5;

long long int F[MX];
long long int IF[MX];

long long int fastPower(long long int x, long long int p)
{
	long long int res = 1;
	while (p)
	{
		if (p & 1) res = (res * x) % MOD;
		p >>= 1;
		x = (x * x) % MOD;
	}
	return res;
}

void init()
{
	if (F[0]) return;
	F[0] = 1;
	for (int i = 1; i < MX; i++)
		F[i] = F[i - 1] * i % MOD;

	IF[MX - 1] = fastPower(F[MX - 1], MOD - 2);
	for (int i = MX - 1; i; i--)
		IF[i - 1] = IF[i] * i % MOD;
}

long long int comb(long long int n, long long int m)
{
	return F[n] * IF[m] % MOD * IF[n - m] % MOD;
}

int main()
{
	long long int n, m, k;
	std::cin >> n >> m >> k;
	init();
	long long int ans = m * fastPower(m - 1, n - k - 1) % MOD * comb(n - 1, k) % MOD;
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
