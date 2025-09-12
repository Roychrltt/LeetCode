#include <bits/stdc++.h>

long long subArrayRanges(vector<int>& A) {
	long res = 0, n = A.size(), j, k;
	stack<int> s;
	for (int i = 0; i <= n; ++i) {
		while (!s.empty() && A[s.top()] > (i == n ? -2e9 : A[i])) {
			j = s.top(), s.pop();
			k = s.empty() ? -1 : s.top();
			res -= (long)A[j] * (i - j) * (j - k);
		}
		s.push(i);
	}
	s = stack<int>();
	for (int i = 0; i <= n; ++i) {
		while (!s.empty() && A[s.top()] < (i == n ? 2e9 : A[i])) {
			j = s.top(), s.pop();
			k = s.empty() ? -1 : s.top();
			res += (long)A[j] * (i - j) * (j - k);
		}
		s.push(i);
	}
	return res;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 76.23%
