#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& prevCost) {
	std::vector<long long> preNext(27);
	std::vector<long long> prePrev(27);
	for (int i = 0; i < 26; i++)
	{
		preNext[i + 1] = preNext[i] + nextCost[i];
		prePrev[i + 1] = prePrev[i] + prevCost[i];
	}
	long long ans = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == t[i]) continue;
		int a = s[i] - 'a';
		int b = t[i] - 'a';
		long long int minNext, minPrev;
		if (a < b)
		{
			minNext = preNext[b] - preNext[a];
			minPrev = prePrev[26] - prePrev[b + 1] + prePrev[a + 1];
		}
		else
		{
			minNext = preNext[26] - preNext[a] + preNext[b];
			minPrev = prePrev[a + 1] - prePrev[b + 1];
		}
		ans += std::min(minNext, minPrev);
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
// runtime beats 88.87%
// memory beats 17.91%
