#include <bits/stdc++.h>

class Solution {

	bool check(int i, int n, vector<int>& c) {
		return (c[(n + i - 1) % n] != c[i] && c[i] != c[(i + 1) % n]);
	}

	public:
	int numberOfAlternatingGroups(vector<int>& c, int k) {
		int count = 0;
		int n = c.size();
		int sum = 0;
		for (int i = 0; i < k - 2; i++)
			if (check(i, n, c))
				sum++;
		if (sum == k - 2)
			count++;
		for (int i = 1; i < n; i++) {
			if (check(i - 1, n, c))
				sum--;
			if (check((i + k - 3) % n, n, c))
				sum++;
			if (sum == k - 2)
				count++;
		}
		return count;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 86.61%
// memory beats 91.84%
