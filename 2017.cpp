#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

long long gridGame(std::vector<std::vector<int>>& grid) {
	int n = grid[0].size();
	long long sum1 = std::accumulate(gris[0].begin(), grid[0].end(), 0LL);
	long long sum2 = 0;
	long long ans = sum1;
	for (int i = 0; i < n; i++)
	{
		sum1 -= grid[0][i];
		ans = std::min(ans, std::max(sum1, sum2));
		sum2 += grid[1][i];
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
// runtime beats 100%
// memory beats 61.54%
