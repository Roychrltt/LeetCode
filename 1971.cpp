#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int d) {
	std::unordered_map<int, std::vector<int>> graph;

	for (auto& p : edges)
	{
		graph[p[0]].push_back(p[1]);
		graph[p[1]].push_back(p[0]);
	}

	std::queue<int> q;
	q.push(source);
	std::unordered_set<int> visited;
	visited.insert(source);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (node == d) return true;
		for (int x : graph[node])
		{
			if (visited.find(x) == visited.end())
			{
				visited.insert(x);
				q.push(x);
			}
		}
	}
	return false;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 38.10%
// memory beats 27.52%
