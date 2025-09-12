#include <bits/stdc++.h>

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	vector<int> price(n, 1e9);
	price[src] = 0;
	for (int i = 0; i <= k; i++)
	{
		vector<int> copy(price);
		for (auto& v : flights)
		{
			if (price[v[0]] == 1e9) continue;
			copy[v[1]] = min(copy[v[1]], price[v[0]] + v[2]);
		}
		price = copy;
	}
	return price[dst] == 1e9 ? -1 : price[dst];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 73.95%
// memory beats 97.40%
