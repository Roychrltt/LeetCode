#include <bits/stdc++.h>

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
	int n = startTime.size();
	vector<vector<int>> jobs(n, vector<int>(3));
	for (int i = 0; i < n; i++)
	{
		jobs[i][0] = startTime[i];
		jobs[i][1] = endTime[i];
		jobs[i][2] = profit[i];
	}
	sort(jobs.begin(), jobs.end(), [](auto& a, auto& b){return a[1] < b[1];});
	vector<int> dp(n + 1);
	for (int i = 0; i < n; i++)
	{
		int p = lower_bound(jobs.begin(), jobs.begin() + i, jobs[i][0], [&](auto& e, int lower){return e[1] <= lower;}) - jobs.begin();
		dp[i + 1] = max(dp[i], dp[p] + jobs[i][2]);
	}
	return dp[n];
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
