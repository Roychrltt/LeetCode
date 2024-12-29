#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int numWays(std::vector<std::string>& words, std::string target) {
	const int MOD = 1e9 + 7;
	int n = words[0].size(),m = target.size();
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
	for(int i = 0; i < n + 1; i++)
		f[i][0] = 1;
	std::vector<std::vector<int>> count(n, std::vector<int>(26));
	for(int i = 0; i < n; i++)
		for(const auto & w : words)
			count[i][w[i] - 'a']++;

	for(int i = 0;i < n; i++)
		for(int j = 0;j < m ;j++)
			f[i + 1][j + 1] = (((long long)count[i][target[j] - 'a'] * f[i][j] + f[i][j + 1]) % MOD);

	return f[n][m];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 77.13%
// memory beats 53.04%
