#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxTotalReward(vector<int>& r) {
	std::ranges::sort(r);
	r.erase(unique(r.begin(), r.end()), r.end());
	int rvb = r.back();
	r.pop_back();
	bitset<50000> f{1};
	for (int v : r)
	{
		int shift = f.size() - v;
		if (shift < v) f |= f << v;
		else f |= f << shift >> (shift - v); 
	}
	for (int i = rvb - 1; ; i--)
		if (f.test(i)) return i + rvb;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 91.09%
// memory beats 59.41%
