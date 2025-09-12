#include <bits/stdc++.h>

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	vector<int> left(n), right(n);
	left[0] = 0, right[n - 1] = n - 1;
	vector<int> s;
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && heights[s.back()] > heights[i])
		{
			int idx = s.back();
			s.pop_back();
			right[idx] = i - idx - 1;
		}
		s.push_back(i);
	}
	while (!s.empty())
	{
		int idx = s.back();
		s.pop_back();
		right[idx] = n - idx - 1;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && heights[s.back()] > heights[i])
		{
			int idx = s.back();
			s.pop_back();
			left[idx] = idx - i - 1;
		}
		s.push_back(i);
	}
	while (!s.empty())
	{
		int idx = s.back();
		s.pop_back();
		left[idx] = idx;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, heights[i] * (right[i] + left[i] + 1));
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
// runtime beats 78.23%
// memory beats 14.39%
