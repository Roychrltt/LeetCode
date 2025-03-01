#include <bits/stdc++.h>

class Solution {
	static inline int partition(int s, int m)
	{
		if (s == m) return 1;
		for (int i = 10; i <= std::min(1000, s); i *= 10)
		{
			if (partition(s / i, m - s % i)) return 1;
		}
		return 0;
	}
public:
	int punishmentNumber(int n) {
		int ans = 0;
		int m = 1;
		while (m <= n)
		{
			if (partition(m * m, m))
				ans += m * m;
			if (m % 9) m += 8;
			else m++;
		}
		return ans;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 95.72%
