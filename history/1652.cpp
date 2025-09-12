#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> f(std::vector<int>& code, int k) {
	int n = code.size();
	std::vector<int> ans(n, 0);

	if (k == 0) return ans;

	int temp = 0;
	int start = (k > 0) ? 1 : n + k;
	int end = (k > 0) ? k : n - 1;
	for (int i = start; i <= end; i++)
	{
		temp += code[i % n];
	}
	for (int i = 0; i < n; i++)
	{
		ans[i] = temp;
		temp -= code[(start + i) % n];
		temp += code[(end + i + 1) % n];
	}
	return ans;
}

int main()
{
	std::vector<int> v = {5,7,1,4};
	std::vector<int> ans = f(v, 3);
	for (int i : ans)
		std::cout << i << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 85.82%
