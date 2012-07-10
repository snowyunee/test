#include <iostream>
#include "l1.h"
#include "l2.h"


int main(int argc, char** argv)
{
	CubeStickers a;
	std::cout << a.isPossible( {"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"} ) << ": no" << std::endl;
	std::cout << a.isPossible( {"purple","orange","orange","purple","black","orange","purple"}) << ": no" << std::endl;
	std::cout << a.isPossible( {"red","yellow","blue","red","yellow","blue","red","yellow","blue"}) << ": yes" << std::endl;
	
	CubeAnts b;
	std::cout << b.getMinimumSteps( {7,7,3,3,7,7,3,3} ) << ": 2" << std::endl;
	std::cout << b.getMinimumSteps( {0,1,1}) << ": 1" << std::endl;
	std::cout << b.getMinimumSteps( {0}) << ": 0" << std::endl;
	std::cout << b.getMinimumSteps( {5,4}) << ": 2" << std::endl;
	}
