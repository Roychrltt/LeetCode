#include <bits/stdc++.h>

class DSU {
	public:

		std::vector<int> v1, v2;

		// number of nodes, better do n + 1
		DSU(int n)
		{
			v1.resize(n);
			v2.resize(n, 0);
			for (int i = 0; i < n; ++i)
				v1[i] = i;
		}

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
};

std::vector<int> f(int c, std::vector<std::vector<int>>& cons, std::vector<std::vector<int>>& q)
{
	DSU dsu(c + 1);
	for (const auto& v : cons) dsu.unite(v[0], v[1]);
	std::vector<int> grid(c + 1), on(c + 1, 1);
	std::map<int, std::set<int>> map;
	for (int i = 1; i <= c; i++)
	{
		int x = dsu.find(i);
		int xx = dsu.find(x);
		if (xx != x)
		{
			dsu.v1[i] = xx;
			continue;
		}
		if (x > i)
		{
			dsu.v1[i] = i;
			dsu.v1[x] = i;
		}
	}
	for (int i = 1; i <= n; i++)
		map[dsu.find(i)].insert(i);
	int n = q.size();
	std::vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		int a = q[i][0], b = q[i][1];
		int x = dsu.find(b);
		if (a == 1)
		{
			if (on[b]) ans.push_back(b);
			else if (map[x].size() > 0) ans.push_back(*(map[x].begin()));
			else ans.push_back(-1);
		}
		else
		{
			on[b] = 0;
			map[x].erase(b);
		}
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
// runtime beats %
// memory beats %
