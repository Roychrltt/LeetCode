#include <bits/stdc++.h>

int maximalRectangle(vector<vector<char>>& matrix) {
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int>> d(n, vector<int>(m));
	vector<int> s;

	for (int j = 0; j < m; j++)
	{
		int cnt = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (matrix[i][j] == '1') d[i][j] = ++cnt;
			else cnt = 0;
		}
	}

	vector<vector<int>> h(n, vector<int>(m)), right(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (!s.empty() && d[i][s.back()] > d[i][j])
			{
				int idx = s.back();
				s.pop_back();
				right[i][idx] = j - idx - 1;
			}
			s.push_back(j);
		}
		while (!s.empty())
		{
			int idx = s.back();
			s.pop_back();
			right[i][idx] = m - idx - 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			while (!s.empty() && d[i][s.back()] > d[i][j])
			{
				int idx = s.back();
				s.pop_back();
				h[i][idx] = idx - j + right[i][idx];
			}
			s.push_back(j);
		}
		while (!s.empty())
		{
			int idx = s.back();
			s.pop_back();
			h[i][idx] = idx + 1 + right[i][idx];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (d[i][j] == 0) continue;
			ans = max(ans, d[i][j] * h[i][j]);
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
// runtime beats 86.61%
// memory beats 52.14%
