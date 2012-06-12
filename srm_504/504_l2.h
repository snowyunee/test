#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
//#include <boost/iterator/counting_iterator.hpp>

class MathContest
{
 public:
  int countBlack(std::string ballSequence, int repetitions)
  {

    std::string temp = ballSequence;
    for(int i=0; i<repetitions-1; ++i)
    {
      ballSequence.append(temp);
    }
    
    int begin = 0;
    int end = ballSequence.size();
    int diff = 1;
    int diff_temp = -1;
    char b = 'B';
    char w = 'W';
    int b_count = 0;
    while(begin != end)
    {
      if(ballSequence[begin] == b)
        ++b_count;

      if(ballSequence[begin] == b)
      {
        std::swap(b, w);
      }
      else // white
      {
        std::swap(begin, end);
        std::swap(diff, diff_temp);
      }

      begin += diff;
      //std::cout << begin << ", " << end << std::endl;
    }
    return b_count;
  }
};
