#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string repeatLimitedString(std::string s, int repeatLimit) {
	int array[26] = {0};
	for (char c : s)
		array[c - 'a']++;
	std::string ans = "";
	while (true)
	{
		for (int i = 25; i >= 0; i--)
		{
			if (array[i] > 0 && (ans.length() == 0 || ans[ans.length() - 1] != i + 'a'))
			{
				int sum = std::accumulate(array + i + 1, array + 26, 0);
				int count = std::min(array[i], repeatLimit);
				if (sum && array[i] > 1 && repeatLimit > 1)
					count = 1;
				ans += std::string(count, i + 'a');
				array[i] -= count;
				if (sum)
					break;
			}
		}
		if (std::accumulate(array, array + 26, 0) == 0)
			break ;
		int x = 0;
		for (int i = 25; i >= 0; i--)
		{
			if (array[i] > 0)
			{
				x = i;
				break;
			}
		}
		if (ans[ans.length() - 1] == x + 'a')
			break;
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
// runtime beats 55.95%
// memory beats 6.37%
