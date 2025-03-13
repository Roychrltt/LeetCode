#include <bits/stdc++.h>

int	f(int t, std::vector<int>& start, std::vector<int>& end)
{
	int n = start.size();
	std::vector<int> suf(n);
	start.push_back(t);
	suf[n - 1] = t - end[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		int cur = start[i + 1] - end[i];
		suf[i] = std::max(cur, suf[i + 1]);
	}
	int cur = start[0];
	int ans;
	if (end[0] - start[0] <= suf[1])
		ans = start[1];
	else
		ans = start[1] - end[0] + start[0];
	if (end[1] - start[1] <= start[0] ||
			n > 2 && end[1] - start[1] <= suf[2])
		ans = std::max(ans, start[2] - end[0]);
	else
		ans = std::max(ans, start[2] - end[0] - (end[1] - start[1]));
	int pre = start[0];
	for (int i = 2; i < n; i++) {
		int x = start[i - 1] - end[i - 2];
		pre = std::max(x, pre);
		if (pre >= end[i] - start[i] ||
				(i < n - 1 && end[i] - start[i] <= suf[i + 1]))
			cur = start[i + 1] - end[i - 1];
		else
			cur = start[i + 1] - end[i - 1] - (end[i] - start[i]);
		ans = std::max(ans, cur);
	}
	return ans;
}

int main()
{
	std::vector<int> start = {0, 3, 7, 9};
	std::vector<int> end = {1, 4, 8, 10};
	int ans = f(10, start, end);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 96.21%
