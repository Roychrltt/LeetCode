#include <bits/stdc++.h>

int f(int n, std::vector<std::vector<int>> e, int k)
{
	if (k >= n) return 0;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i;
	auto find = [&](this auto&& find, int x)
	{
		if (x == v[x]) return x;
		v[x] = find(v[x]);
		return v[x];
	};

	auto unit = [&](int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y) return false;
		f[x] = y;
		return true;
	};

	std::sort(e.begin(), e.end(), [](const std::vector<int>& a, const std::vector<int>& b){return a[2] < b[2];});
	int cnt = n;
	for (const auto& ee : e)
	{
		int u = ee[0], v = ee[1], w = ee[2];
		if (unit(u, v)) cnt--;
		if (cnt <= k) return w;
	}
	return -1;
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
