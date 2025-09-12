#include <bits/stdc++.h>

int numberOfWeakCharacters(vector<vector<int>>& v) {
	int cnt = 0;
	array<int, 100002> maxD = {};
	for (auto& p : v) maxD[p[0] - 1] = max(maxD[p[0] - 1], p[1]);
	for (int i = 100001; i > 0; i--)
		maxD[i - 1] = max(maxD[i], maxD[i - 1]);

	for (auto& p : v) cnt += p[1] < maxD[p[0]];
	return cnt;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 97.37%
// memory beats 38.07%
