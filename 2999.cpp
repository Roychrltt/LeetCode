#include <bits/stdc++.h>

long long numberOfPowerfulInt(long long l, long long r, int k, string s) {
	string sl = to_string(l - 1);
	string sr = to_string(r);
	int n = s.size();
	auto cal = [&](string str) -> long long
	{
		int len = str.size();
		if (len < n) return 0;
		else if (len == n) return str >= s;

		long long cnt = 0;
		string suf = str.substr(len - n);

		for (int i = 0; i < len - n; i++)
		{
			if (k < (str[i] - '0'))
			{
				cnt += (long)pow(k + 1, pre - i);
				return cnt;
			}
			cnt += (long)(str[i] - '0') * (long)pow(k + 1, pre - 1 - i);
		}
		if (suf >= s) cnt++;

		return cnt;
	};
	return cal(sr) - cal(sl);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 65.59%
