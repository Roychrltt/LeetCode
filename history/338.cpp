#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> f(int n) {
	std::vector<int> bits(n + 1);
	int h = 0;
	for (int i = 1; i <= n; i++) {
		if ((i & (i - 1)) == 0) {
			h = i;
		}
		bits[i] = bits[i - h] + 1;
	}
	return bits;
}

int main()
{
	std::vector<int> v = f(10);
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}
// runtime beats 100%
// memory beats 18.58%
