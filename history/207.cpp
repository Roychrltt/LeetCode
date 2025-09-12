#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>

bool f(int n, std::vector<std::vector<int>>& pres)
{
	std::vector<std::vector<int>> graph(n);
	std::vector<int> inDegree(n, 0);

	for (const auto& pre : pres)
	{
		graph[pre[1]].push_back(pre[0]);
		inDegree[pre[0]]++;
	}

	std::queue<int> q;
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	std::vector<int> order;
	while (!q.empty())
	{
		int course = q.front();
		q.pop();
		order.push_back(course);

		for (int neighbour : graph[course])
			if (--inDegree[neighbour] == 0) q.push(neighbour);
	}
	return order.size() == n;
}

int main()
{
	std::vector<std::vector<int>> v = {{0,1},{1,0}, {2,0}, {3,0}, {2,1}, {4,1}, {4,3}};
	bool ans = f(5, v);
	std::cout << std::boolalpha << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 76.12%
