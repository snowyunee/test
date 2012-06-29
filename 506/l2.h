#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <boost/iterator/counting_iterator.hpp>

class SlimeXSlimesCity
{
public:
	int merge(std::vector<int> population)
	{
		std::sort(population.begin(), population.end());
		std::vector<int64_t> acc(population.size());
		acc[0] = population[0];
		for (size_t i = 1; i < population.size(); ++i)
		{
			acc[i] += acc[i-1] + population[i];
		}
		//std::partial_sum(population.begin(), population.end(), acc.begin());
		int count = 1;
		for (auto i=population.size()-1; i > 0; --i)
		{
			if (population[i] > acc[i-1])
			   	break;
			++count;
		}
		return count;
	}
};
