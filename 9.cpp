#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool f(int x) {
	if (x < 0)
		return false;
	long long int num = 0;
	long long int temp = x;
	while (x > 0)
	{
		int digit = x % 10;
		num = num * 10 + digit;
		x /= 10;
	}
	return (temp == num);
}

int main()
{
	int i = 987656789;
	bool ans = f(i);
	std::cout << std::boolalpha << ans << std::endl;
	int j = 876544678;
	ans = f(j);
	std::cout << std::boolalpha << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 46.49%
