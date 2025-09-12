#include <bits/stdc++.h>

int f(int n)
{
	std::vector<int> memo(1 << n, -1);
	auto dfs = [&](this auto&& dfs, int i) -> int
	{
		if (i == (1 << n) - 1) return 1;

		int& res = memo[i];
		if (res != -1) return res;
		res = 0;
		int count = __builtin_popcount((unsigned)i) + 1;
		for (int j = 0; j <= n; j++) {
			if (!(i & (i >> (j - 1))) && (count % j == 0 || j % count == 0))
				res += dfs(i | (i << (j - 1)));
		}
		return res;
	};
	return dfs(0);
}

int countArrangement(int n) {
	if (n < 4)
		return n;
	int vis[16] = {0};
	int ans = 0;
	auto dfs = [&](this auto&& dfs, int pos) -> void
	{
		if (pos > n)
		{
			ans++;
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && (i % pos == 0 || pos % i == 0)) {
				vis[i] = true;
				dfs(pos + 1);
				vis[i] = false;
			}
		}
	};
	dfs(1);
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 20.58%
// memory beats 92.21%
