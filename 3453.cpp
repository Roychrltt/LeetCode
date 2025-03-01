#include <bits/stdc++.h>

double separateSquares(vector<vector<int>>& s) {
	long double up = 0, down = 0;
	sort(s.begin(), s.end(), [](auto& a, auto& b){
			if (a[1] < b[1]) return true;
			else if (a[1] == b[1]) return a[2] > b[2];
			else return false;
			});
	down = s[0][1];
	long double sum = 0;
	for (auto& a : s)
	{
		up = std::max((long double)a[1] + a[2], up);
		sum += (double)a[2] * a[2];
	}
	sum /= 2;
	const double E = 10e-6;
	while (down + E < up)
	{
		long double area = 0;
		long double mid = (down + up) / 2;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i][1] > mid) break;
			area += (long double)s[i][2] * std::min((long double)s[i][2], mid - s[i][1]);
		}
		if (area < sum) down = mid;
		else up = mid;
	}
	return down;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 39.32%
// memory beats 25.91%
