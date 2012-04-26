
#include <assert.h>
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

void print_picture(std::vector<std::string> picture)
{
  std::cout << std::endl << "print picture : " << std::endl;
  for (auto& str : picture)
  {
    std::cout << "str:" << str << std::endl;
  }
  std::cout << std::endl;
}

class ColoredStrokes
{
 public:
  int getLeast(std::vector<std::string> picture)
  {
    // process R
    int strokes_count = 0;
    for(auto& h : picture)
    {
      bool is_exist_stroke = false;
      for(auto& ch : h)
      {
        if (('R' == ch || 'G' == ch) && is_exist_stroke == false)
        {
          is_exist_stroke = true;
          ++strokes_count;
        }
        else if (('B' == ch || '.' == ch) && is_exist_stroke == true)
        {
          is_exist_stroke = false;
        }

        if ('R' == ch)
          ch = '.';
        if ('G' == ch)
          ch = 'B';

        //print_picture(picture);
      }
    }


    // process B
    for(uint32_t i=0; i<picture[0].size(); i++)
    {
      bool is_exist_stroke = false;
      for(auto& h : picture)
      {
        char& ch = *(h.begin() + i);
        //print_picture(picture);
        assert(ch == 'B' || ch == '.');
        if (('B' == ch) && is_exist_stroke == false)
        {
          is_exist_stroke = true;
          ++strokes_count;
        }
        else if (('.' == ch) && is_exist_stroke == true)
        {
          is_exist_stroke = false;
        }

        if ('B' == ch)
          ch = '.';

        //print_picture(picture);
      }
    }

    return strokes_count;
  }

};



int main(int argc, const char *argv[])
{
	ColoredStrokes a;
	
  long r = 0;
  r = a.getLeast(std::vector<std::string>({"...", "..."}));
  std::cout << r << " == 0" << std::endl;

  r = a.getLeast(std::vector<std::string>({"..B.", "..B."}));
  std::cout << r << " == 1" << std::endl;

  r = a.getLeast(std::vector<std::string>({".BB."}));
  std::cout << r << " == 2" << std::endl;

  r = a.getLeast(std::vector<std::string>({"...B..", ".BRGRR", ".B.B.."}));
  std::cout << r << " == 3" << std::endl;

  r = a.getLeast(std::vector<std::string>({"...B..", ".BRBRR", ".B.B.."}));
  std::cout << r << " == 4" << std::endl;

  r = a.getLeast(std::vector<std::string>({"GR", "BG"}));
  std::cout << r << " == 4" << std::endl;
    	
    	
  return 0;
}




