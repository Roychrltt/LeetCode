#include <bits/stdc++.h>

class DSU {
	std::vector<int> v1, v2;

	int find(int i)
	{
		if (v1[i] != i)
			v1[i] = find(v1[i]);
		return v1[i];
	}

	void unite(int i, int k)
	{
		int a = find(i);
		int b = find(k);
		if (a != b)
		{
			if (v2[a] > v2[b])
				v1[b] = a;
			else if (v2[a] < v2[b])
				v1[a] = b;
			else
			{
				v1[b] = a;
				v2[a]++;
			}
		}
	}

	bool is_same_set(int a, int b)
	{
		return find(a) == find(b);
	}

public:

	int f(int n, std::vector<std::vector<int>>& v)
	{
		std::vector<int> count(n);
		std::vector<std::unordered_set> node(n);
		v1.resize(n);
		v2.resize(n, 0);
		for (int i = 0; i < n; ++i)
			v1[i] = i;
		for (auto& p : v) {
			unite(p[0], p[1]);
			count[find(p[0])]++;
			node[find(p[0])].insert(p[0]);
			node[find(p[0])].insert(p[1]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (node[i] == 0) continue;
			int x = node[i];
			if (count[i] == x * (x - 1) / 2)
				ans++;
		}
		return ans;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
