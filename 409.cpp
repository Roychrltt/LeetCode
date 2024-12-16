#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	int count = 0;
	int array[52] = {0};
	for(char c : s) {
		int i;
		if (c >= 'a' && c <= 'z')
			i = c - 'a';
		else
			i = c - 'A' + 26;
		array[i]++;
		if (array[i] % 2)
			count++;
		else    
			count--;
	}
	if (count > 1)
		return s.length() - count + 1;
	return s.length();
}

int main()
{
	std::string s = "ahsbsbabahbs";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 68.68%
