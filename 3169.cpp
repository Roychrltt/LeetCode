#include <bits/stdc++.h>

int countDays(int days, vector<vector<int>>& meetings) {
	sort(meetings.begin(), meetings.end());
	int n = meetings.size();
	int ans = meetings[0][0] - 1;
	int lastDay = meetings[0][1];
	for (int i = 1; i < n; i++)
	{
		ans += max(meetings[i][0] - lastDay - 1, 0);
		lastDay = max(lastDay, meetings[i][1]);
	}
	if (lastDay != days)
		ans += days - lastDay;
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 48.98%
// memory beats 97.11%
