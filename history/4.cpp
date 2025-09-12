#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <climits>

double f(std::vector<int>& nums1, std::vector<int>& nums2) {
	int m = nums1.size(); 
	int n = nums2.size();
	int total = m + n;
	int pos1 = total / 2;
	int pos2 = (total % 2) ? pos1 : pos1 - 1;
	if (m == 0)
		return (n % 2 == 0) ? (nums2[pos2] + nums2[pos1]) / 2.0 : nums2[pos1];
	if (n == 0)
		return (m % 2 == 0) ? (nums1[pos2] + nums1[pos1]) / 2.0 : nums1[pos1];
	int begin1 = 0, begin2 = 0;
	int n1, n2;
	while (begin1 + begin2 <= pos1)
	{
		int v1 = (begin1 < m) ? nums1[begin1] : INT_MAX; 
		int v2 = (begin2 < n) ? nums2[begin2] : INT_MAX; 
		if (v1 <= v2)
		{
			if (begin1 + begin2 == pos2)
				n2 = v1;
			if (begin1 + begin2 == pos1)
				n1 = v1;
			begin1++;
		}
		else
		{
			if (begin1 + begin2 == pos2)
				n2 = v2;
			if (begin1 + begin2 == pos1)
				n1 = v2;
			begin2++;
		}
	}
	return (total % 2) ? static_cast<double>(n1) : static_cast<double>(n1 + n2) / 2;
}

int main()
{
	std::vector<int> v = {1,2};
	std::vector<int> vv = {3,4};
	double ans = f(v, vv);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 76.79%
