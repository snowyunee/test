
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

class PermutationSignature
{
 public:
  std::vector<int> reconstruct(std::string signature)
  {
    if (signature.size() < 1) return std::vector<int>();

    std::vector<int> result(signature.size()+1);
    result[0] = 1;
    int result_index = 1;
    int min = 1;
    for (char& a : signature)
    {
      switch(a)
      {
        case '|': result[result_index] = result[result_index-1] + 1; break;
        case 'D': result[result_index] = result[result_index-1] - 1; break;
      };
      min = std::min(result[result_index], min);
      ++result_index;
      std::cout << ", a---:" << a;
    }

    int diff = 1 - min;
    //std::cout << min << ", " << diff << std::endl;
    std::vector<int> count(result.size());
    for (size_t i = 0; i < result.size(); ++i)
    {
      result[i] += diff;
      ++count[result[i]];
    }

    std::vector<int> will_come_count(count);
    std::cout << "will come:";
    print_vec(will_come_count);

    std::cout << "result i" ;
    for (size_t i = 0; i < result.size(); ++i)
    {
      std::cout << "result i" << result[i];
      result[i] += count[result[i]] - will_come_count[result[i]];
      --will_come_count[result[i]];
    }

    std::cout << "will come:"; print_vec(will_come_count); 

    return result;
  }
};


int main(int argc, const char *argv[])
{
	PermutationSignature a;
	
  std::vector<int> r;

  std::cout << "result i---";
  r = a.reconstruct("|||||");
  print_vec(r);
  std::cout << " == 1,2,3,4,5,6" << std::endl;

  r = a.reconstruct("D|");
  print_vec(r);
	std::cout << " == 2,1,3" << std::endl;

  r = a.reconstruct("||||D");
  print_vec(r);
	std::cout << " == 1,2,3,4,6,5" << std::endl;

  r = a.reconstruct("D||D|D");
  print_vec(r);
	std::cout << " == 2,1,3,5,4,7,6" << std::endl;

  return 0;
}




