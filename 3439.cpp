#include <bits/stdc++.h>

int f(int eventTime, int k, std::vector<int>& startTime, std::vector<int>& endTime) {
	int n = startTime.size();
	int ans = startTime[0];
	startTime.push_back(eventTime);
	for (int i = 1; i <= k && i <= n; i++)
		ans += startTime[i] - endTime[i - 1];
	if (k == n) return ans;

	std::cout << ans << std::endl;
	int cur = ans - startTime[0] + startTime[k + 1] - endTime[k];
	ans = std::max(ans , cur);
	std::cout << ans << std::endl;
	for (int i = k + 2; i <= n; i++)
	{
		cur += startTime[i] - endTime[i - 1];
		cur -= startTime[i - k - 1] - endTime[i - k - 2];
		ans = std::max(cur, ans);
		std::cout << ans << std::endl;
	}
	return ans;
}

int main()
{
	std::vector<int> start = {21,67,151,448};
	std::vector<int> end = {23,132,219,449};
	int ans = f(482, 2, start, end);
	return 0;
}
// runtime beats 83.13%
// memory beats 93.55%
