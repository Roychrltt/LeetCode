#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minDominoRotations(std::vector<int>& A, std::vector<int>& B) {
	std::vector<int> countA(6), countB(6), same(6);
	int n = A.size();
	for (int i = 0; i < n; ++i)
	{
		countA[A[i] - 1]++;
		countB[B[i] - 1]++;
		if (A[i] == B[i])
			same[A[i] - 1]++;
	}
	for (int i = 0; i < 6; ++i)
	{
		int a = countA[i], b = countB[i];
		if (a + b - same[i] == n)
			return n - std::max(a, b);
	}
	return -1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 37.07%
