#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	std::stack<int> stack;
	stack.push(-1);
	int ans = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			stack.push(i);
		else
		{
			stack.pop();
			if (stack.empty())
				stack.push(i);
			else
				ans = std::max(ans, i - stack.top());
		}
	}
	return ans;
}

int main()
{
	std::string s = "(((()))))))()()()()()()())())))))())((((((()))))";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 12.44%
