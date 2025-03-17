#include <bits/stdc++.h>

class Solution {
	array<int, 3> maxD(vector<vector<int>>& ps, int skip = -1) {
		int sum[2] = {INT_MAX, INT_MIN}, sum_i[2] = {0, 0};
		int diff[2] = {INT_MAX, INT_MIN}, diff_i[2] = {0, 0};
		for (int i = 0; i < ps.size(); ++i) {
			if (i == skip)
				continue;
			if (sum[0] > ps[i][0] + ps[i][1]) {
				sum[0] = ps[i][0] + ps[i][1];
				sum_i[0] = i;
			}
			if (sum[1] < ps[i][0] + ps[i][1]) {
				sum[1] = ps[i][0] + ps[i][1];
				sum_i[1] = i;
			}
			if (diff[0] > ps[i][0] - ps[i][1]) {
				diff[0] = ps[i][0] - ps[i][1];
				diff_i[0] = i;
			}
			if (diff[1] < ps[i][0] - ps[i][1]) {
				diff[1] = ps[i][0] - ps[i][1];
				diff_i[1] = i;
			}
		}
		if (sum[1] - sum[0] > diff[1] - diff[0])
			return {sum[1] - sum[0], sum_i[0], sum_i[1]};
		return {diff[1] - diff[0], diff_i[0], diff_i[1]};
	}

	public:
	int minimumDistance(vector<vector<int>>& p) {
		auto [_, i, j] = maxD(p);
		return min(maxD(p, i)[0], maxD(p, j)[0]);
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 85.85%
// memory beats 75.47%
