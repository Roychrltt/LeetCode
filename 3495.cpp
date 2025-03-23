#include <bits/stdc++.h>

class Solution {
	long long solve(long long l, long long r)
	{
		long long int ans = 0;
		for (long long i = 1; pow(4, i - 1) <= r; i++)
		{
			if (pow(4, i) < l) continue;
			long long len = std::min(r, (long long)pow(4, i) - 1) - l + 1;
			ans += len * i;
			l = pow(4, i);
		}
		return (ans + 1) / 2;
	}
public:
	long long minOperations(vector<vector<int>>& queries) {
		long long ans = 0;
		for (int i = 0; i < queries.size(); i++)
		{
			ans += solve(queries[i][0], queries[i][1]);
		}
		return ans;
	}
};

int main()
{
	std::vector<std::vector<int>> v = {{1, 2}, {2, 4}, {5, 17}};
	long long int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
