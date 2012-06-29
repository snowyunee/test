
#include <vector>
#include <algorithm>

class SlimeXSlimeRancher2
{
public:
	int train(std::vector<int> attributes)
	{
		int max = *std::max_element(attributes.begin(), attributes.end());
		int sum = std::accumulate(attributes.begin(), attributes.end(), 0);
		return max*attributes.size() - sum;
	}
};
