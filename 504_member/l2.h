#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <boost/iterator/counting_iterator.hpp>

class PerfectSequences
{
public:
	std::string fixIt(std::vector<int> seq)
	{
		if(seq.size() <= 1) return "Yes";

		for(int one : seq)
		{
			int64_t add=0;
			int64_t mul=1;
			if(false == getTotalExceptOne(one, seq.begin(), seq.end(), add, mul))
				continue;

			if(mul <= 1)	// 이런 경우는 없다.
				continue;

			if((add % (mul - 1)) == 0)
			{
				if(one == (add / (mul - 1))) // 못 바꾸는 경우
					continue;

			   	return "Yes";
			}
		}
		return "No";
	}
	bool getTotalExceptOne(int except_one, std::vector<int>::iterator begin,
			std::vector<int>::iterator end,
			int64_t& add, int64_t& mul)
	{
		bool is_skiped = false;
		for(auto i=begin; i!=end; ++i)
		{
			if(is_skiped == false && except_one == *i)
			{
				is_skiped = true;
				continue;
			}
			add += *i;
			mul *= *i;

			if(mul >= (int64_t(65536)*int64_t(65536)))
			   	return false;
		}
		return true;
	}
};
