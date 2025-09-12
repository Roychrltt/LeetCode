#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<vector<int>> pres(n);
	vector<int> inDegree(n);

	for(int i = 0; i < n; i++) {
		for(int x : graph[i])
			pres[x].push_back(i);
		inDegree[i] = graph[i].size();
	}
	queue<int> q;
	for(int i = 0; i < n; i++)
		if(inDegree[i] == 0)
			q.push(i);

	vector<int> ans;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for(int x : pres[cur])
			if(--inDegree[x] == 0) q.push(x);
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 62.80%
// memory beats 43.05%
