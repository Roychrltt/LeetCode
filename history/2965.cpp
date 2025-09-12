#include <bits/stdc++.h>

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
	int a(0), b(0);
	int n = grid.size();
	vector<int> v(n * n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[grid[i][j] - 1]++ > 0)
				a = grid[i][j];
		}
	}
	for (int i = 0; i < n * n; i++)
		if (v[i] == 0)
			b = i + 1;

	return {a, b};
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 74.78%
// memory beats 77.75%
