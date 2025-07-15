#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}, {4, 5}, {6, 7}, {6, 8}, {8, 9}};
	int n = 10;
	std::vector<int> f(n), rank(n);
	
	for (int i = 0; i < n; ++i)
		f[i] = i;
	
	auto find = [&](this auto&& find, int i)
	{
		if (f[i] != i)
			f[i] = find(f[i]);
		return f[i];
	};
	
	auto unit = [&](int i, int j)
	{
		i = find(i);
		j = find(j);
		if (i != j)
		{
			if (rank[i] > rank[j])
				f[j] = i;
			else if (rank[i] < rank[j])
				f[i] = j;
			else
			{
				f[j] = i;
				rank[i]++;
			}
		}
	};
	for (const auto& e : edges)
		unit(e[0], e[1]);
	std::copy(f.begin(), f.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	__Made in France__
}
