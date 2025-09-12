#include <bits/stdc++.h>

int minimumOperationsToMakeKPeriodic(string s, int k) {
	int n = s.length();
	unordered_map<string, int> map;
	int count = 0;
	for (int i = 0; i < n; i += k)
	{
		string sub = s.substr(i, k);
		count = max(count, ++map[sub]);
	}
	return n / k - count;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 68.14%
// memory beats 51.47%
