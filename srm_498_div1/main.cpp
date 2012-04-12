
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


class FoxSequence
{
 public:
  enum State{kIncrease_1=0, kDecrease_1, kStay, kIncrease_2, kDecrease_2, kError};

  std::string isValid(const std::vector<int>& seq)
  {
    // that 0 < a < b <= c < d < N-1  
    State state = kIncrease_1;
    int common_difference = 0;
    int prev_value = seq[0];
    bool result = false;

    for (int i=1; i<seq.size();)
    {
      int cur_value = seq[i];
      int cur_diff = cur_value - prev_value;
      State old_state = state;

      switch(state)
      {
        case kIncrease_1:
          result = process_sequence_increase_1(cur_value, prev_value, cur_diff, &common_difference, &state);
          break;
        case kDecrease_1:
          result = process_sequence_decrease_1(cur_value, prev_value, cur_diff, &common_difference, &state);
          break;
        case kStay:
          result = process_sequence_stey(cur_value, prev_value, cur_diff, &common_difference, &state);
          break;
        case kIncrease_2:
          result = process_sequence_increase_1(cur_value, prev_value, cur_diff, &common_difference, &state);
          break;
        case kDecrease_2:
          result = process_sequence_decrease_1(cur_value, prev_value, cur_diff, &common_difference, &state);
          if (result == true && state == kError) result = false;
          break;
      };

      if (old_state == state)
      {
        prev_value = seq[i];
        i++;
      }


      if (false == result ||
          state == kError)
      {
        std::cout << "i:" << i << ", old_state:" << old_state << ", state:" << state;
        break;
      }
    }

    if (false == result ||
        state == kError)
      return "NO";

    return "YES";
  }

 private:
  bool process_sequence_increase_1(int cur_value, int prev_value, int cur_diff, int* common_difference, State* next_state)
  {
    if (*common_difference == 0)
    {
      *common_difference = cur_diff;
      if (*common_difference <= 0)
        return false; 
      return true;
    }

    if (cur_diff == 0 ||
        (cur_diff > 0 && *common_difference != cur_diff) )
      return false ;
    if (cur_diff < 0)
      if (false == go_next_state(next_state, common_difference))
        return false;
    return true;
  }

  bool process_sequence_decrease_1(int cur_value, int prev_value, int cur_diff, int* common_difference, State* next_state)
  {
    if (*common_difference == 0)
    {
      *common_difference = cur_diff;
      if (*common_difference >= 0)
        return false; 
      return true;
    }

    if (cur_diff < 0 && *common_difference != cur_diff)
      return false ;
    if (cur_diff >= 0)
      if (false == go_next_state(next_state, common_difference))
        return false;

    return true;
  }

  bool process_sequence_stey(int cur_value, int prev_value, int cur_diff, int* common_difference, State* next_state)
  {
    if (cur_diff < 0) 
      return false;
    if (cur_diff == 0) return true;

    if (false == go_next_state(next_state, common_difference)) 
      return false;
    return true;
  }

  bool go_next_state(State* next_state, int* common_difference)
  {
    *next_state = (State)((int)(*next_state) + 1);
    if (*next_state >= kError) 
      return false;
    *common_difference = 0;
    return true;
  }

};


int main(int argc, const char *argv[])
{
	FoxSequence fs;
	
	std::vector<int> v;

	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);
	std::cout << fs.isValid(v) << " == YES" << std::endl;

	v.clear();
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(4);
	std::cout << fs.isValid(v) << " == YES" << std::endl;

	v.clear();
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);
	v.push_back(1);
	v.push_back(9);
	v.push_back(5);
	v.push_back(1);
	std::cout << fs.isValid(v) << " == YES" << std::endl;

	v.clear();
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	std::cout << fs.isValid(v) << " == NO" << std::endl;

	v.clear();
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	std::cout << fs.isValid(v) << " == NO" << std::endl;

	v.clear();
	v.push_back(6);
	v.push_back(1);
	v.push_back(6);
	std::cout << fs.isValid(v) << " == NO" << std::endl;

  return 0;
}




