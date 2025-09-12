#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& banned, int n, int maxSum) {
	std::ranges::sort(banned);
	int sum = 0, cur = 1, i = 0, count = 0;
	int o = banned.size();
	while (sum < maxSum && cur <= n)
	{
		if (sum + cur > maxSum)
			break ;
		if (i < o && cur == banned[i])
		{
			while (i < o && banned[i] == cur)
				i++;
			cur++;
			continue;
		}
		sum += cur;
		cur++;
		count++;
	}
	return count;
}

int main()
{
	std::vector<int> v = {1, 6, 5};
	int ans = f(v, 5, 6);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 87.06%
// memory beats 98.04%
