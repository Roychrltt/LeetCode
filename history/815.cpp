#include <bits/stdc++.h>

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
	if (source == target) return 0;
	unordered_map<int, vector<int>> adj;
	for (int i = 0; i < routes.size(); i++)
		for (auto x : routes[i])
			adj[x].push_back(i);

	queue<int> q;
	unordered_set<int> vis;
	for (auto x : adj[source])
	{
		q.push(x);
		vis.insert(x);
	}
	int ans = 1;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int route = q.front();
			q.pop();
			for (auto x : routes[route])
			{
				if (x == target) return ans;
				for (auto next : adj[x])
				{
					if (!vis.count(next))
					{
						vis.insert(next);
						q.push(next);
					}
				}
			}
		}
		ans++;
	}
	return -1;
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
