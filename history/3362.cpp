#include <bits/stdc++.h>

int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
	ranges::sort(q);
	priority_queue<int> endPoints;
	priority_queue<int, vector<int>, greater<>> chosen;
	int count = 0, n = nums.size(), j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j < q.size() && q[j][0] == i)
			endPoints.push(q[j++][1]);
		nums[i] -= chosen.size();
		while (nums[i] > 0 && !endPoints.empty() && endPoints.top() >= i)
		{
			count++;
			chosen.push(endPoints.top());
			endPoints.pop();
			nums[i]--;
		}
		if (nums[i] > 0) return -1;
		while (!chosen.empty() && chosen.top() == i)
			chosen.pop();
	}
	return endPoints.size();
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
