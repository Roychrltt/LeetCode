#include <bits/stdc++.h>

vector<int> minCosts(vector<int>& cost) {
	int n = cost.size();
	vector<int> ans(n);
	int cur = cost[0];
	for (int i = 0; i < n; i++)
	{
		cur = min(cur, cost[i]);
		ans[i] = cur;
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
// runtime beats %
// memory beats %
