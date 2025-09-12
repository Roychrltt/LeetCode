#include <bits/stdc++.h>

long long maxArea(vector<vector<int>>& coords) {
	map<long long, pair<int, int>> xmap, ymap;
	for (auto& p : coords)
	{
		long long x = p[0], y = p[1];
		if (xmap.find(x) == xmap.end())
		{
			xmap[x].first = y;
			xmap[x].second = y;
		}
		else
		{
			if (y < xmap[x].first) xmap[x].first = y;
			if (y > xmap[x].second) xmap[x].second = y;
		}
		if (ymap.find(y) == ymap.end())
		{
			ymap[y].first = x;
			ymap[y].second = x;
		}
		else
		{
			if (x < ymap[y].first) ymap[y].first = x;
			if (x > ymap[y].second) ymap[y].second = x;
		}
	}
	long long ans = -1;
	long long mx = xmap.rbegin()->first, my = ymap.rbegin()->first, mmx = xmap.begin()->first, mmy = ymap.begin()->first;
	for (auto& [x, p] : xmap)
	{
		if (p.first != p.second)
		{
			if (mx != x) ans = max(ans, (mx - x) * (p.second - p.first));
			if (mmx != x) ans = max(ans, (x - mmx) * (p.second - p.first));
		}
	}
	for (auto& [y, p] : ymap)
	{
		if (p.first != p.second)
		{
			if (my != y) ans = max(ans, (my - y) * (p.second - p.first));
			if (mmy != y) ans = max(ans, (y - mmy) * (p.second - p.first));
		}
	}
	return ans;
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
