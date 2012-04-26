
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


class AnagramFree
{
 public:
  int getMaximumSubset(std::vector<std::string> s)
  {
    for(auto& str : s)
    {
      std::sort(str.begin(), str.end());
    }
    std::sort(s.begin(), s.end());
    auto unique_e = std::unique(s.begin(), s.end());
    return unique_e - s.begin();
  }
};



int main(int argc, const char *argv[])
{
	AnagramFree a;
	
  long r = 0;
  r = a.getMaximumSubset(std::vector<std::string>( {"abcd","abdc","dabc","bacd"} ));
  std::cout << r << " == 1" << std::endl;

  r = a.getMaximumSubset(std::vector<std::string>( {"abcd","abac","aabc","bacd"} ));
  std::cout << r << " == 2" << std::endl;

  r = a.getMaximumSubset(std::vector<std::string>( {"aa","aaaaa","aaa","a","bbaaaa","aaababaa"} ));
  std::cout << r << " == 6" << std::endl;

  r = a.getMaximumSubset(std::vector<std::string>( {"creation","sentence","reaction","sneak","star","rats","snake"} ));
  std::cout << r << " == 4" << std::endl;

  return 0;
}


