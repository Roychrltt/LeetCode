#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string addBinary(std::string a, std::string b) {
	std::string ans;
	int carry = 0;
	int n = a.length();
	int m = b.length();
	while (n || m || carry)
	{
		if (n) carry += a[n-- - 1] - '0';
		if (m) carry += b[m-- - 1] - '0';

		ans += carry % 2 + '0';
		carry /= 2;
	}
	std::reverse(ans.begin(), ans.end());
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
// memory beats 51.08%
