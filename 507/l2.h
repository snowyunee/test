#ifndef SRM_507_L2
#define SRM_507_L2

#include <string>
#include <vector>
#include <algorithm>

class CubeStickers
{
public:
	std::string isPossible(std::vector<std::string> sticker)
	{
		int count = 0;
		std::sort(sticker.begin(), sticker.end());
		auto iter1 = std::unique(sticker.begin(), sticker.end());
		count += iter1 - sticker.begin();
		auto iter2 = std::unique(iter1, sticker.end());
		count += iter2 - iter1;
		return (count >=6) ? "Yes" : "No";
	}
};

#endif
