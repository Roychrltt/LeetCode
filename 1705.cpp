#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int eatenApples(std::vector<int>& apples, std::vector<int>& days) {
	int ans = 0, i = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
	for (; i < apples.size(); i++)
	{
		while (!pq.empty() && pq.top().first == i)
			pq.pop();
		if (apples[i])
			pq.emplace(i + days[i], apples[i]);
		if (!pq.empty())
		{
			ans++;
			auto [day, num] = pq.top();
			pq.pop();
			if (num > 1)
				pq.emplace(day, num - 1);
		}
	}
	while (1)
	{
		while (!pq.empty() && pq.top().first <= i)
			pq.pop();
		if (pq.empty())
			break;
		auto [day, num] = pq.top();
		pq.pop();
		int k = std::min(num, day - i);
		ans += k;
		i += k;
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
// runtime beats 97.99%
// memory beats 77.18%
