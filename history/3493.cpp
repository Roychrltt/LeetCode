#include <bits/stdc++.h>

class Solution {
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

    int intersect(unordered_map<int, int>& x, unordered_map<int, int>& y)
    {
        int count = 0;
        for (auto& [c, _] : x)
            if (y.find(c) != y.end())
                count++;
        return count;
    }

public:
    int numberOfComponents(vector<vector<int>>& p, int k) {
        int n = p.size();
        vector<unordered_map<int, int>> map(n);
        v1.resize(n);
        v2.resize(n, 0);
		for (int i = 0; i < n; ++i)
        {
			v1[i] = i;
            for (int x : p[i])
                map[i][x]++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                if (intersect(map[i], map[j]) >= k)
                    unite(i, j);
        }
        unordered_set<int> set;
        for (int i = 0; i < n; i++)
            set.insert(find(i));
        return set.size();
    }
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 74.68%
// memory beats 78.04%
