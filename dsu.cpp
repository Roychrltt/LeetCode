#include <vector>
#include <iostream>

class DSU {
std::vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }


    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                std::swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    bool is_same_set(int a, int b)
    {
        return find(a) == find(b);
    }
};

int main() {
    DSU dsu(5); // Create a DSU with 5 elements (0 to 4)

    dsu.unite(0, 1); // Union 0 and 1
    dsu.unite(2, 3); // Union 2 and 3
    dsu.unite(1, 3); // Union 1 and 3 (now 0, 1, 2, 3 are connected)

    std::cout << dsu.is_same_set(0, 3) << "\n"; // Output: 1 (true)
    std::cout << dsu.is_same_set(0, 4) << "\n"; // Output: 0 (false)

    return 0;
}

std::queue<int> q;

std::vector<int> ans;
while (!q.empty())
{
	int c = q.front();
	q.pop();
	ans.push_back(c);

	for (int neighbour : graph[c])
		if (--inDegree[neighbour] == 0) q.push(neighbour);
}
