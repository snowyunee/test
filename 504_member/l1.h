
#include <vector>
#include <algorithm>

class SentenceCapitalizerInator
{
public:
	std::string fixCaps(std::string paragraph)
	{
		if(paragraph.empty()) return paragraph;
		paragraph[0] += 'A' - 'a';
		std::string find_string(". ");
		auto search_point = paragraph.begin();
		while(1)
		{
			search_point = std::search(search_point, paragraph.end(),
				   	find_string.begin(), find_string.end());
			if(paragraph.end() == search_point)
				break;

			search_point += 2;
			*search_point += 'A' - 'a';
		}
		return paragraph;
	}
};
