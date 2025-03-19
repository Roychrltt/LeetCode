#include <bits/stdc++.h>

vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> ans(n, 0); 
	vector<int> s;  

	for (int i = 0; i < n; i++) {
		while (!s.empty() && temperatures[i] > temperatures[s.back()]) {
			int index = s.back(); 
			s.pop_back();
			ans[index] = i - index; 
		}
		s.push_back(i);
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
// runtime beats 96.79%
// memory beats 64.36%
