#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>

class MyQueue {

	std::stack<int> in_stack, out_stack;

	void transfer()
	{
		while (!in_stack.empty())
		{
			out_stack.push(in_stack.top());
			in_stack.pop();
		}
	}

	public:
		MyQueue() {}

		void push(int x) {
			in_stack.push(x);
		}

		int pop() {
			if (out_stack.empty()) {
				transfer();
			}
			int topElement = out_stack.top();
			out_stack.pop();
			return topElement;
		}

		int peek() {
			if (out_stack.empty()) {
				transfer();
			}
			return out_stack.top();
		}

		bool empty() {
			return in_stack.empty() && out_stack.empty();
		}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 17.61%
