
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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


class AdditionGame
{
 public:
   int getMaximumPoints(int A, int B, int C, int N)
   {
      int max_points = 0;
      std::vector<int> points;
      points.push_back(A);
      points.push_back(B);
      points.push_back(C);
      for (int i=0; i<N; ++i)
      {
        std::vector<int>::iterator max_itr = std::max_element(points.begin(), points.end());
        if (*max_itr <= 0) break;
        max_points += *max_itr;
        --(*max_itr);
      }
      return max_points;
   }
};


int main(int argc, const char *argv[])
{
	AdditionGame a;
	
	std::cout << a.getMaximumPoints(3,4,5,3) << " == 13" << std::endl;
	std::cout << a.getMaximumPoints(1,1,1,8) << " == 3" << std::endl;
	std::cout << a.getMaximumPoints(3,4,48,40) << " == 1140" << std::endl;
	std::cout << a.getMaximumPoints(36,36,36,13) << " == 446" << std::endl;
	std::cout << a.getMaximumPoints(8,2,6,13) << " == 57" << std::endl;


  return 0;
}




