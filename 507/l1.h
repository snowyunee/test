#ifndef SRM_507_L1
#define SRM_507_L1

#include <vector>

class CubeAnts
{
public:
	int getMinimumSteps(std::vector<int> pos)
	{
		int step = 0;
		for(auto position : pos)
		{
			int cur_step = 0;
			if (position == 0) cur_step = 0;
			if (position == 1 || position == 3 || position == 4) cur_step = 1;
			if (position == 2 || position == 5 || position == 7) cur_step = 2;
			if (position == 6) cur_step = 3;

			step = std::max(step, cur_step);
		}
		return step;
	}
};

#endif
