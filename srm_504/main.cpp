#include <iostream>
#include "504_l1.h"
#include "504_l2.h"
//#include "504_l3.h"

int main()
{

  //Algrid a;
  //std::cout << a.makeProgram({"WWWWWWW", "WWWWWWB", "BBBBBWW"}) << "{\"WWWWWWW\", \"WWWWWWB\", \"BBBBBWW\"}" << std::endl;
  //std::cout << a.makeProgram({"BBBBB", "WBWBW"}) << "{\"BBBBB\", \"WWBWB\" }" << std::endl;
  //std::cout << a.makeProgram({"BBBB", "BBBB", "BBWB", "WWBB", "BWBB"}) << "{ }" << std::endl;
  //std::cout << a.makeProgram({"WWBBBBW", "BWBBWBB", "BWBBWBW", "BWWBWBB"} ) << "{\"WWBBBBW\", \"BBBBBWB\", \"BBBBBBB\", \"BBBWBBB\" } " << std::endl;
  //

  //ComparerInator a;
  //std::cout << a.makeProgram({1}, {2}, {2}) << " : 1" << std::endl;
  //std::cout << a.makeProgram( {1,3}, {2,1}, {2,3}) << " Returns: 7" << std::endl;
  //std::cout << a.makeProgram( {1,3,5}, {2,1,7}, {2,3,5}) << " Returns: -1" << std::endl;
  //std::cout << a.makeProgram( {1,3,5}, {2,1,7}, {1,3,5}) << " Returns: 1" << std::endl;
  //std::cout << a.makeProgram( {1,2,3,4,5,6,7,8,9,10,11}, {5,4,7,8,3,1,1,2,3,4,6}, {1,2,3,4,3,1,1,2,3,4,6}) << " Returns: 7" << std::endl; 
  //std::cout << a.makeProgram( {1,5,6,7,8}, {1,5,6,7,8}, {1,5,6,7,8}) << " Returns: 1" << std::endl;

  MathContest a;
  std::cout << a.countBlack("BBWWB", 1) << ": 2" << std::endl;
  std::cout << a.countBlack("BBB", 10) << ": 1" << std::endl;
  std::cout << a.countBlack("BW", 10) << ": 20" << std::endl;
  std::cout << a.countBlack("WWWWWWWBWWWWWWWWWWWWWW", 1) << ": 2" << std::endl;

  return 0;
}
