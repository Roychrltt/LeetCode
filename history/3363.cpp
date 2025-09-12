#include <bits/stdc++.h>

int maxCollectedFruits(vector<vector<int>>& v) {
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((j < i || i < j) && i + j < n - 1)
				v[i][j] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += v[i][i];
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j < n; j++)
			v[i][j] += max({v[i - 1][j - 1], v[i - 1][j], (j + 1 < n) ? v[i - 1][j + 1] : 0});
	for (int j = 1; j < n; j++)
		for (int i = j + 1; i < n; i++)
			v[i][j] += max({v[i - 1][j - 1], v[i][j - 1], (i + 1 < n) ? v[i + 1][j - 1] : 0});
	return ans + v[n - 1][n - 2] + v[n - 2][n - 1];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 68.15%
// memory beats 94.27%
