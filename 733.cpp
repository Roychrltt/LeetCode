#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
	int tmp = image[sr][sc];
	if (tmp == color)
		return image;
	image[sr][sc] = color;
	if (sr > 0 && image[sr - 1][sc] == tmp)
		floodFill(image, sr - 1, sc, color);
	if (sr + 1 < image.size() && image[sr + 1][sc] == tmp)
		floodFill(image, sr + 1, sc, color);
	if (sc > 0 && image[sr][sc - 1] == tmp)
		floodFill(image, sr, sc - 1, color);
	if (sc + 1 < image[0].size() && image[sr][sc + 1] == tmp)
		floodFill(image, sr, sc + 1, color);
	return image;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 6.46%
