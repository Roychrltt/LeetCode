#include <bits/stdc++.h>

class Solution {
    int isPrime (int n)
    {
        if (n == 1) return 0;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int ans = 0;
        int prev = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!isPrime(nums[i])) continue;
            if (prev == -1)
                prev = i;
            else
                ans = max(ans, i - prev);
        }
        return ans;
    }
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 91.38%
// memory beats 52.45%
