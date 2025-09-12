#include <bits/stdc++.h>

int f(std::vector<int>& nums, int k)
{
	std::priority_queue<long long int, std::vector<long long>, std::greater<long long>> pq(nums.begin(), nums.end());
	int count = 0;
	while (pq.top() < k)
	{
		long long int x = pq.top();
		pq.pop();
		long long int y = pq.top();
		pq.pop();
		long long z = std::min(x, y) * 2 + std::max(x, y);
		pq.push(z);
		count++;
	}
	return count;
}

int main()
{
	std::vector<int> v = {1, 1, 2, 4, 9};
	int ans = f(v, 20);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
