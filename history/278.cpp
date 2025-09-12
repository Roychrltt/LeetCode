#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
	public:
		int firstBadVersion(int n) {
			int left = 1, right = n;
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (isBadVersion(mid))
					right = mid - 1;
				else
					left = mid + 1;
			}
			return left;
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
// memory beats 28.11%
