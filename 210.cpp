#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

vector<int> findOrder(int n, vector<vector<int>>& pres) {
	std::vector<std::vector<int>> graph(n);
	std::vector<int> inDegree(n, 0);

	for (const auto& pre : pres) {
		graph[pre[1]].push_back(pre[0]);
		inDegree[pre[0]]++;
	}

	std::queue<int> q;
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	std::vector<int> order;
	while (!q.empty()) {
		int course = q.front();
		q.pop();
		order.push_back(course);

		for (int neighbour : graph[course]) {
			inDegree[neighbour]--;
			if (inDegree[neighbour] == 0)
				q.push(neighbour);
		}
	}
	if (order.size() == n)
		return order;
	return {};
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 66.79%
