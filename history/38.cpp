#include <bits/stdc++.h>

string countAndSay(int n) {
	int tmp = 1;
	string s = "1";
	while (tmp < n){
		int cnt = 1;
		string res = "";
		for(int i = 1; i < s.size(); i++){
			if(s[i] == s[i - 1])
				cnt++;
			else
			{
				res.push_back(cnt + '0');
				res.push_back(s[i - 1]);
				cnt = 1;
			}
		}
		res.push_back(cnt + '0');
		res.push_back(s.back());
		s = res;
		tmp++;
	}
	return s;        
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 97.64%
