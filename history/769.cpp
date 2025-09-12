#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>

int f(std::vector<int>& arr)
{
	int n = arr.size();
	std::vector<int> count(n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		count[arr[i]] = 1;
		if (std::accumulate(count.begin(), count.begin() + i + 1, 0) == i + 1)
			ans++;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {3,2,1,0};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 14.53%
