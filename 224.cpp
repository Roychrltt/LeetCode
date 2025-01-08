#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int calculate(std::string s) {
	std::stack<int> ops;
	ops.push(1);
	int sign = 1;

	int ans = 0;
	int n = s.length();
	int i = 0;
	while (i < n)
	{
		if (s[i] == '+')
			sign = ops.top();
		else if (s[i] == '-')
			sign = -ops.top();
		else if (s[i] == '(')
			ops.push(sign);
		else if (s[i] == ')')
			ops.pop();
		else if (s[i] != ' ')
		{
			long num = 0;
			while (i < n && s[i] >= '0' && s[i] <= '9')
				num = num * 10 + s[i++] - '0';
			ans += sign * num;
			i--;
		}
		i++;
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
// memory beats 43.60%
