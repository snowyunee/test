
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


void print_vec(const std::vector<int>& r)
{
  for (size_t i=0; i<r.size(); ++i)
  {
    std::cout << r[i] << ",";
  }
  std::cout << std::endl;
}

class Filtering
{
 public:
  std::vector<int> designFilter(std::vector<int> sizes, std::string outcome)
  {
    if (sizes.size() != outcome.size())
      return std::vector<int>();

    std::vector<char> sorted;
    sorted.resize(100);
    int index = 0;
    for_each(sizes.begin(), sizes.end(), [&outcome, &sorted, &index](int size) {
      //                   std::cout << "size:" << size << ", filter:" << outcome.at(index++) << ", index:" << index << std::endl;
      sorted[size] = outcome.at(index++);
    });

    auto a_min = find_if(sorted.begin(), sorted.end(), [](char filter) {
                         if (filter == 'A') return true;
                         return false;
                         });
    auto r_min = find_if(a_min, sorted.end(), [](char filter) {
                         if (filter == 'R') return true;
                         return false;
                         });
    auto a_max = a_min;
    for (auto itr = r_min; itr != a_min; --itr)
    {
      if (*itr == 'A')
      {
        a_max = itr;
        break;
      }
    }
    auto second_a_min = find_if(r_min, sorted.end(), [](char filter) {
                         if (filter == 'A') return true;
                         return false;
                         });

    if (second_a_min == sorted.end())
    {
      std::vector<int> result = {(int)(a_min-sorted.begin()), int(a_max-sorted.begin())};
      return result;
    }

  return std::vector<int>();
  }
};



int main(int argc, const char *argv[])
{
	Filtering a;
	
  std::vector<int> r;

  r = a.designFilter(std::vector<int> {3,4,5,6,7}, std::string("AAAAA"));
  print_vec(r);
  std::cout << " == 3,7" << std::endl;

  r = a.designFilter(std::vector<int> {3,4,5,6,7}, std::string("AARAA"));
  print_vec(r);
  std::cout << " == { }" << std::endl;

  r = a.designFilter(std::vector<int> {3,4,5,6,7}, std::string("RAAAA"));
  print_vec(r);
  std::cout << " == 4,7" << std::endl;

  r = a.designFilter(std::vector<int> {68,57,7,41,76,53,43,77,84,52,34,48,27,75,36}, std::string("RARRRARRRARARRR"));
  print_vec(r);
  std::cout << " == 48, 57" << std::endl;

  r = a.designFilter(std::vector<int> {26,81,9,14,43,77,55,57,12,34,29,79,40,25,50}, std::string("ARAAARRARARARAA"));
  print_vec(r);
  std::cout << " == { }" << std::endl;

  return 0;
}




