#include <bits/stdc++.h>

class Solution {
	bool isPrime(int n)
	{
		if (n == 3) return true;
		int i = 2;
		while (i * i <= n)
		{
			if (n % i == 0) return false;
			i++;
		}
		return true;
	}
	public:
	vector<int> closestPrimes(int left, int right) {
		if (left == right || right <= 2) return {-1, -1};
		if (left <= 2) return {2, 3};
		int a = -1, b = -1, min = -1, max = -1;
		int sum = INT_MAX;
		for (int i = left; i <= right; i++)
		{
			if (!isPrime(i)) continue;
			if (a == -1) a = i;
			else if (b == -1) b = i;
			else
			{
				a = b;
				b = i;
			}
			if (a > 0 && b > 0)
			{
				if (b - a == 2) return {a, b};
				else if (b - a < sum)
				{
					sum = b - a;
					min = a, max = b;
				}
			}
		}      
		if (min > 0 && max > 0) return {min, max};
		return {-1, -1};
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
// memory beats 96.60%
