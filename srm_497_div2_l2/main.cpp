
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


class MakeSquare
{
 public:
   int minChanges(std::string s)
   {
     int n = s.size();
     if (n <= 1)
       return 0;

     if (n == 2)
     {
       if (s.at(0) == s.at(1))
         return 0;
       else
         return 1;
     }

     // write which index each alphabet comes up.
     std::vector<std::vector<int> > alphabet_appear('z'+'a');
     for (int i = 0; i < n; ++i)
     {
       alphabet_appear[(int)s.at(i)].push_back(i);
     }

     std::vector<std::vector<int> > s_appear(n);
     for (int i = 0; i < n; ++i)
     {
       if (alphabet_appear[(int)s.at(i)].size() > 0)
       {
         s_appear[i] = alphabet_appear[(int)s.at(i)];
         // don't choose
         s_appear[i].push_back(-1);
       }
       else
       {
         // don't choose
         s_appear[i].push_back(-1);
       }
     }

     std::vector<int> case_count(n + 1);
     case_count[n] = 1;
     for (int split_point = n - 1; split_point >= 1; --split_point)
     {
       case_count[split_point] = case_count[split_point + 1] * s_appear[split_point].size();
       std::cout << "split_point:" << split_point << ", case_count:" << case_count[split_point] << std::endl;
     }

     int min_cost=n;
     for (int split_point=1; split_point<n-1; ++split_point)
     {
       int choosable_min=0;
       int choosable_max=split_point;
       for (int case_index=0; case_index < case_count[split_point]; ++case_index)
       {
         int total_cost = 0;
         int prev_left_match_index = -1;
         int prev_right_match_index = split_point-1;
         int current_case = case_index;
         std::vector<int> match_index(n);

         // make matches in order
         for (int right_current = split_point; right_current < n-1; ++right_current)
         {
           int alphabet_appear = current_case / case_count[right_current + 1];
           current_case %= case_count[right_current + 1];

           match_index[right_current] = alphabet_appear;

           // no match
           if (alphabet_appear < 0) 
             continue;

           int left_match_index = s_appear[right_current][alphabet_appear];

           // no match
           if (left_match_index < choosable_min || left_match_index >= choosable_max)
             continue;

           int cost = std::max((left_match_index - prev_left_match_index -1),
                               (right_current - prev_right_match_index - 1));

           if (cost < 0)
           {
             std::cout << "left:" << left_match_index - prev_left_match_index -1
                 << ", " << left_match_index << ", " << prev_left_match_index
                 << ", right:" << right_current - prev_right_match_index - 1
                 << ", " << right_current << ", " << prev_right_match_index << std::endl;
             assert(0);
           }

           total_cost += (cost > 0) ? cost : 0;

           std::cout << s << ", split_point:" << split_point
               << ", match : " << left_match_index << ", " << right_current 
               << ", prev : " << prev_left_match_index << ", " << prev_right_match_index
               << ", cost:" << cost
               << ", tatal_cost:" << total_cost << std::endl;

           choosable_min = left_match_index + 1;
           prev_left_match_index = left_match_index;
           prev_right_match_index = right_current;
         }

         int cost = std::max(choosable_max - 1 - prev_left_match_index -1,
                             n - 1 - prev_right_match_index - 1);
         if (cost < 0)
         {
           std::cout << "left:" << choosable_max - 1 - prev_left_match_index -1
               << ", right:" << n - 1 - prev_right_match_index - 1;
           assert(0);
         }
         total_cost += (cost > 0) ? cost : 0;

         if (total_cost < min_cost)
           min_cost = total_cost;

           //std::cout << s << ", tatal_cost:" << total_cost << std::endl;
       }

     }
     return min_cost;
   }
};


int main(int argc, const char *argv[])
{
	MakeSquare a;
	
	//std::cout << a.minChanges("abcdabgcd") << " == 1" << std::endl;
	//std::cout << a.minChanges("abcdeabce") << " == 1" << std::endl;
	//std::cout << a.minChanges("abcdeabxde") << " == 1" << std::endl;
	std::cout << a.minChanges("aabcaabc") << " == 0" << std::endl;
	//std::cout << a.minChanges("aaaaabaaaaabaaaaa") << " == 2" << std::endl;


  return 0;
}




