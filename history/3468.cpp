#include <bits/stdc++.h>

int countArrays(vector<int>& o, vector<vector<int>>& bounds) {
	int up = INT_MAX, down = INT_MAX;
	for (int i = 0; i < o.size(); i++)
	{
		up = std::min(o[i] - bounds[i][0], up);
		down = std::min(bounds[i][1] - o[i], down);
	}
	return max(down + up + 1, 0);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 89.19%
