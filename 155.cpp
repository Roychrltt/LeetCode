#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class MinStack {
	stack<pair<int, int>> st;

	public:
	MinStack() {
		st.emplace(0, INT_MAX);
	}

	void push(int val) {
		st.emplace(val, min(getMin(), val)); 
	}

	void pop() {
		st.pop();
	}

	int top() {
		return st.top().first;
	}

	int getMin() {
		return st.top().second;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 64.40%
// memory beats 5.25%
