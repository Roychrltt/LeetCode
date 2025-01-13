#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minimumLength(string s) {
	std::vector<int> v(26, 0);
	for (char c : s)
		v[c - 'a']++;
	int count = 0;
	for (int x : v)
	{
		if (x < 3) count += x;
		else count += x % 2 ? 1 : 2;
	}
	return count;
}

	std::vector<int> v(26, 0);
    for (char c : s)
        if (++v[c - 'a'] >= 3) v[c - 'a'] -= 2;
    return std::reduce(v.begin(), v.end());

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 98.79%
// memory beats 86.69%
