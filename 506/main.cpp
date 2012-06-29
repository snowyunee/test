#include <iostream>
#include "l3.h"
#include "l2.h"
#include "l1.h"

int main()
{
	//SlimeXSlimeRancher2 a;
	//std::cout << a.train({900,500,100}) << ":1200" << std::endl;

	SlimeXSlimesCity a;
	std::cout << a.merge({2,3,4}) << ":2" << std::endl;
	std::cout << a.merge({1,2,3}) << ":2" << std::endl;
	std::cout << a.merge({8,2,3,8}) << ":2" << std::endl;
	std::cout << a.merge({1000000000, 999999999, 999999998, 999999997}) << ":3" << std::endl;
	std::cout << a.merge({1,1,1}) << ":3" << std::endl;
	std::cout << a.merge({1, 2, 4, 6, 14, 16, 20}) << ":3" << std::endl;
 


  return 0;
}
