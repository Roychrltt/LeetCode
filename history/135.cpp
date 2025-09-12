#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int candy(vector<int>& r) {
	int n = r.size();
	vector<int> candies(n, 1);

	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (r[i] > r[i - 1]) candies[i] = candies[i - 1] + 1;
	}
	for (int i = n - 1; i > 0; i--)
	{
		if (r[i - 1] > r[i]) candies[i - 1] = max(candies[i - 1], candies[i] + 1);
		ans += candies[i - 1];
	}

	return ans + candies[n - 1];
}

int main()
{
	std::vector<int> v = {1,0,2};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 37.39%
