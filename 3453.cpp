#include <bits/stdc++.h>

double separateSquares(vector<vector<int>>& v) {
	sort(v.begin(), v.end(), [&](auto& a, auto& b){ 
			return (a[1] < b[1] || (a[1] == b[1] && a[2] < b[2]));});
	int n = v.size();
	double bottom = v[0][1];
	double top = bottom;
	long double total = 0;
	for (auto& a : v)
	{
		top = std::max(top, (double)a[1] + a[2]);
		total += (double)a[2] * a[2];
	}
	constexpr double e = 1e-6;
	while (bottom + e < top)
	{
		long double sum = 0;
		double mid = (bottom + top) / 2.0;
		for (auto& a : v)
		{
			if (a[1] < mid)
				sum += (double)a[2] * std::min(mid - a[1], (double)a[2]);
		}
		if (sum * 2 < total)
			bottom = mid;
		else
			top = mid;
	}
	return (top + bottom) / 2.0;
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
