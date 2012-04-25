
#include <algorithm>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>


class PalindromfulString
{
 public:
  long count(int N, int M, int K)
  {
    return static_cast<long>(count(N, M, K, "", 'a'));
  }

  int64_t count(int N, int M, int K, std::string text, char max_char)
  {
    if (N == 0)
    {
      //std::cout << "text:" << text << std::endl;
      // check palindromfull string
      int p_count = 0;
      for (unsigned int i=0; i<text.size()-M+1; ++i)
      {
        bool is_p = true;
        for (unsigned int j=0; j<M/2; ++j)
        {
          if (text.at(i+j) != text.at(i+M-1-j))
          {
            is_p = false;
            break;
          }
        }
        if (is_p) ++p_count;
      }

      if (p_count >= K)
      {
        int64_t cnt = calculate_count(max_char);
        //std::cout << "cnt:" << cnt << std::endl;
        return cnt;
      }

      return 0;
    }

    int64_t total_count = 0;
    total_count += count(N-1, M, K, text + max_char, max_char + 1);
    for (char a='a'; a<max_char; a++)
    {
      total_count += count(N-1, M, K, text + a, max_char);
    }
    return total_count;
  }

  int64_t calculate_count(char max_char)
  {
    int64_t count = 1;
    for (char a='a'; a<max_char; ++a)
    {
      count *= 26 - (a - 'a');
    }
    return count;
  }
};



int main(int argc, const char *argv[])
{
	PalindromfulString a;
	
  long r = 0;
  r = a.count(2,2,1);
  std::cout << r << " == 26" << std::endl;

  r = a.count(2,2,0);
  std::cout << r << " == 676" << std::endl;

  r = a.count(3,2,1);
  std::cout << r << " == 1326" << std::endl;

  r = a.count(4,4,1);
  std::cout << r << " == 676" << std::endl;

  r = a.count(7,3,3);
  std::cout << r << " == 4310176" << std::endl;

  return 0;
}




