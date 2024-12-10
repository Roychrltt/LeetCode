#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& ratings) {
	int sum = 0;
	int n = ratings.size();
	int i = 1;
	while (i < n)
	{
		if (ratings[i] == ratings[i - 1])
		{
			i++;
			continue;
		}

		int maxC = 0;
		while (i < n && ratings[i] > ratings[i - 1])
		{
			maxC++;
			sum += maxC;
			i++;
		}
		if (i == n)
			break;
		int minC = 0;
		while (i < n && ratings[i] < ratings[i - 1])
		{
			minC++;
			sum += minC;
			i++;
		}
		sum -= std::min(minC, maxC);
	}
	return sum + n;
}

int main()
{
	std::vector<int> v = {1,0,2};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 37.39%
