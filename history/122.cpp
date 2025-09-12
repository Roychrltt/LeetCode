#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& prices) {
	int prev = prices[0];
	int profit = 0;
	for (int p : prices) {
		if (p > prev)
			profit += p - prev;
		prev = p;
	}
	return profit;
}

int main()
{
	std::vector<int> v = {7,1,5,3,6,4};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 91.94%
