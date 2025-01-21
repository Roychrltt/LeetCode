#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int lengthAfterTransformations(string s, int t) {
	const int MOD = 1e9 + 7;
	vector<long long> v(26, 0);

	for (char c : s)
		v[c - 'a']++;

	for (int i = 0; i < t; i++) {
		vector<long long> tmp(26);
		for (int i = 0; i < 25; i++)
			tmp[i + 1] =  v[i];
		tmp[0] = v[25];
		tmp[1] = (tmp[1] + v[25]) % MOD;
		v = std::move(tmp);
	}

	long long ans = 0;
	for (long long c : v)
		ans = (ans + c) % MOD;

	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 48.94%
// memory beats 40.94%
