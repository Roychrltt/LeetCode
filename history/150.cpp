#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int evalRPN(vector<string>& tokens) {
	stack<int> st;
	int n = tokens.size();
	for (int i = 0; i < n; i++) {
		string& token = tokens[i];
		if (isNumber(token))
			st.push(atoi(token.c_str()));
		else {
			int num2 = st.top();
			st.pop();
			int num1 = st.top();
			st.pop();
			switch (token[0]) {
				case '+':
					st.push(num1 + num2);
					break;
				case '-':
					st.push(num1 - num2);
					break;
				case '*':
					st.push(num1 * num2);
					break;
				case '/':
					st.push(num1 / num2);
					break;
			}
		}
	}
	return st.top();
}

bool isNumber(string& token) {
	return !(token == "+" || token == "-" || token == "*" || token == "/");
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 21.51%
