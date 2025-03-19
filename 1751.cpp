#include <bits/stdc++.h>

int maxValue(vector<vector<int>>& events, int k) {
	ranges::sort(events, {}, [](auto& e) { return e[1]; });
	int n = events.size();
	vector f(n + 1, vector<int>(k + 1));
	for (int i = 0; i < n; i++) {
		int p = lower_bound(events.begin(), events.begin() + i, events[i][0],[](auto& e, int lower) { return e[1] < lower; }) - events.begin();
		for (int j = 1; j <= k; j++)
			f[i + 1][j] = max(f[i][j], f[p][j - 1] + events[i][2]);
	}
	return f[n][k];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 87.68%
// memory beats 90.35%
