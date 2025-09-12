#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

string clearDigits(string s) {
	std::string ans;
	int count = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (isdigit(s[i])) count++;
		else if (count > 0) count--;
		else ans += s[i];
	}
	reverse(ans.begin(), ans.end());
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
// memory beats 88.69%
