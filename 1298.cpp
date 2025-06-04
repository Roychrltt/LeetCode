#include <bits/stdc++.h>

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
	int n = status.size();
	set<int> waiting;
	queue<int> q;
	int ans = 0;
	for (int x : initialBoxes)
	{
		if (status[x] == 1) q.push(x);
		else waiting.insert(x);
	}

	while (!q.empty())
	{
		int b = q.front();
		q.pop();

		ans += candies[b];
		for (int k : keys[b]) status[k] = 1;
		for (int bb : containedBoxes[b])
		{
			if (status[bb] == 1) q.push(bb);
			else waiting.insert(bb);
		}

		for (int w : waiting)
		{
			if (status[w] == 1)
			{ 
				q.push(w);
				waiting.erase(w);
			}
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
