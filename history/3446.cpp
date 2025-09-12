#include <bits/stdc++.h>

vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
	int n = grid.size();
	vector<int> v;
	vector<vector<int>> ans(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		int j = n - i - 1, k = 0;
		for (int count = 0; count <= i; count++)
			v.push_back(grid[j++][k++]);
		sort(v.begin(), v.end(), greater<int>());
		int a = 0;
		j = n - i - 1, k = 0;
		for (int count = 0; count <= i; count++)
			ans[j++][k++] = v[a++];
		v.clear();
	}
	for (int i = 1; i < n; i++)
	{
		int j = 0, k = i;
		for (int count = 0; count < n - i; count++)
			v.push_back(grid[j++][k++]);
		sort(v.begin(), v.end());
		int a = 0;
		j = 0, k = i;
		for (int count = 0; count < n - i; count++)
			ans[j++][k++] = v[a++];
		v.clear();
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
// runtime beats 100%
// memory beats 95.65%
