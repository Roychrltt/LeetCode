#include <bits/stdc++.h>

 bool checkValidCuts(int n, vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [&](const auto& a, const auto& b)
        { return a[1] < b[1] || (a[1] == b[1] && a[3] > b[3]);});
        int count = 0, begin = v[0][3];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i][1] >= begin) count++;
            if (count == 2) return true;
            begin = max(begin, v[i][3]);
        }
        sort(v.begin(), v.end(), [&](const auto& a, const auto& b)
        { return a[0] < b[0] || (a[0] == b[0] && a[2] > b[2]);});
        count = 0, begin = v[0][2];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i][0] >= begin) count++;
            if (count == 2) return true;
            begin = max(begin, v[i][2]);
        }
        return false;
    }

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 75.27%
// memory beats 92.78%
