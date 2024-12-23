#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int myAtoi(std::string s) {
	long long ans = 0;
	int sign = 1;
	int len = s.length();
	int i = 0;
	while (i < len && s[i] == ' ')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (i < lens && [i] >= '0' && s[i] <= '9')
	{
		ans = ans * 10 + (s[i] - '0');
		if (ans > INT_MAX && sign == -1)
			return INT_MIN;
		else if (ans > INT_MAX && sign == 1)
			return INT_MAX;
		i++;
	}
	return (ans * sign);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 98.29%
