#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& v)
{
	int n = v.size();

	int array[n] = {0};
	return array[3];
}

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
