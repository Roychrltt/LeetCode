#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int valueAfterKSeconds(int n, int k) {
	const int MOD = 1e9 + 7;
	std::vector<int> v(n, 1);
	for (int i = 0; i < k; i++)
		for (int x = 1; x < n; x++)
			v[x] = (v[x] + v[x - 1]) % MOD;
	return (v[n - 1]);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 65.97%
// memory beats 45.49%
