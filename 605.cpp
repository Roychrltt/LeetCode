#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool f(std::vector<int>& f, int n) {
	int count = 0;
	for (int i = 0; i < f.size(); ++i)
	{
		if (f[i] == 0 && (i == 0 || f[i - 1] == 0) && ((i == f.size() - 1) || f[i + 1] == 0))
		{
			f[i] = 1;
			count++;
		}
		if (count >= n)
			return true;
	}
	return false;
}

int main()
{
	std::vector<int> v = {1,0,0,0,1};
	bool ans = f(v, 1);
	std::cout << std::boolalpha << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 67.74%
