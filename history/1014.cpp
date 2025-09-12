#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxScoreSightseeingPair(vector<int>& v) {
	int leftMax = v[0];
	int ans = 0;
	for (int i = 1; i < v.size(); i++)
	{
		leftMax = std::max(leftMax, v[i - 1] + i - 1);
		ans = std::max(ans, leftMax + v[i] - i);
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
// runtime beats 100%
// memory beats 55.58%
