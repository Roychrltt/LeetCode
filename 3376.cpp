#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int findMinimumTime(std::vector<int>& strength, int k) {
	int ans = std::numeric_limits<int>::max();
	int n = strength.size();
	std::vector<int> visited(n);
	std::function<void(int, int)> dfs = [&](int i, int cur) {
		if (cur >= ans)
			return;
		if (i == n)
		{
			ans = cur;
			return;
		}
		int x = 1 + k * i;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j])
			{
				visited[j] = 1;
				dfs(i + 1, cur + (strength[j] - 1) / x + 1);
				visited[j] = 0;
			}
		}
	};
	dfs(0, 0);
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
