#include <bits/stdc++.h>

bool carPooling(vector<vector<int>>& trips, int capacity) {
	vector<int> dif(1002);
	for (auto& v : trips)
	{
		dif[v[1]] += v[0];
		dif[v[2]] -= v[0];
	}
	for (int i = 1; i < 1002; i++)
		dif[i] += dif[i - 1];

	for (int x : dif)
		if (x > capacity) return false;

	return true;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 30.48%
