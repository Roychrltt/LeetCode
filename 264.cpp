#include <bits/stdc++.h>

int f(int n)
{
	std::array<int, 3> arr = {2, 3, 5};
	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
	std::set<int> vis;
	pq.push(1);
	vis.insert(1);
	for (int i = 0; i < n - 1; i++) {
		long long int cur = pq.top();
		pq.pop();
		for (int prime : arr)
		{
			long long int product = prime * cur;
			if (vis.find(product) == vis.end())
			{
				pq.push(product);
				vis.insert(product);
			}
		}
	}
	return pq.top();
}

int f(int n)
{
	int p2 = 0, p3 = 0, p5 = 0;
	std::vector<int> k(n);
	k[0] = 1;
	for (int i = 1; i < n; i++) {
		k[i] = std::min(k[p2] * 2, std::min(k[p3] * 3, k[p5] * 5));
		if (k[i] == k[p2] * 2) p2++;
		if (k[i] == k[p3] * 3) p3++;
		if (k[i] == k[p5] * 5) p5++;
	}
	return k[n - 1];
}

int main()
{
	std::cout << f(1640) << std::endl;
	std::cout << f(10) << std::endl;
	std::cout << f(20) << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 84.62%
