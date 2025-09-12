#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
	int n = A.size();
	std::bitset<50> bsA;
	std::bitset<50> bsB;
	std::vector<int> ans(n, 0);

	for (int i = 0; i < n; ++i) {
		bsA[A[i] - 1] = true;
		bsB[B[i] - 1] = true;
		std::bitset<50> tmp = bsA & bsB;
		ans[i] = tmp.count();
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
// memory beats 95.90%
