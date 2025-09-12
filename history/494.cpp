#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int findTargetSumWays(std::vector<int>& nums, int target) {
	int c = std::reduce(nums.begin(), nums.end()) - std::abs(target);
	if (c < 0 || c % 2) return 0;
	c >>= 1;
	int n = nums.size();
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(c + 1));
	f[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= c; j++) {
			if (j < nums[i])
				f[i + 1][j] = f[i][j];
			else
				f[i + 1][j] = f[i][j] + f[i][j - nums[i]];
		}
	}
	return f[n][c];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 45.09%
