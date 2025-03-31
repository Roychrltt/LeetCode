#include <bits/stdc++.h>

int eraseOverlapIntervals(vector<vector<int>>& v) {
	int n = v.size();
	sort(v.begin(), v.end(), [&](const auto& a, const auto& b)
			{ return a[1] < b[1];});
	int ans = 0;
	int prev = v[0][1];
	for (int i = 1; i < n; i++)
	{
		if (v[i][0] < prev) ans++;
		else prev = v[i][1];
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
// runtime beats 55.46%
// memory beats 88.49%
