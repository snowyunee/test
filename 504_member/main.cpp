#include <iostream>
#include "l3.h"
#include "l2.h"
#include "l1.h"

int main()
{
//  RectangleArea a;
//  std::cout << a.minimumQueries( {"YNY", "NYN", "YNY"}) << ": 1" << std::endl;
//	std::cout << a.minimumQueries( 
//	  {"NNYYYNN", "NNNNNYN", "YYNNNNY", "NNNYNNN", "YYNNNNY"}
//	  ) << ": 2" << std::endl;
//
//	std::cout << a.minimumQueries( 
//		//{"NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN"}	
//		 // ) << ": 35" << std::endl;
//
//	//{"NNYNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYNYNNYNNYNNNNNNNNNNNYNNYYNYNNNNNNYYNYNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNYNYNNNYYN", "NNNNYNYNNYNNYNNNNNNNNNNNYNNYYNYNNNNNNYYNYNNNNNNN"}
//	//	  ) << ": 31" << std::endl;
//	
//
//				{"NNNNNNNNNNNNNNNNNNNNYYNNNNNNYNNNNNNNNNNNNNNYN", "NNNNNNNNNNNNYNNNNNNYNNNNYYNNYNNYNNNNNNNNNNNYN", "NNNNNNNNNNNNNNYNNYNNNYNNNNNNYNNNNNNNNNNNNNNYN", "YNNYNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNNNNYNNNN", "NNNNNNNNYNNNNNYNNNNYNNNNNNNNNNNYNNNNNNNNNNNYN", "NNNYNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNN", "NNNNYNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNYNNNN", "YNNYYNNNNNYNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNYNNNNNNNNYNNNYNNNNNYYNNNNNYNNNNY", "NNNNNNNNNNNNNNYNNNNNYNNNYYNNNNNNNNNNNNNNNNNYN", "NNNYNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN", "NNNNNNNNYNNNNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNN", "NNNNNYYYNYNNNYNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNY", "NNYNNYYNNYNNNYNNNNYNNNYNNNYNNNNNYNNNNNNYNYNNY", "NNNNNNNNNNNNNNNNNYNNNNNNNYNNYNNNNNNNNNNNNNNNN", "YNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNN", "YNNNNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNYNN", "NNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNNNNYYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNYNYNNNYNNNNYNNNNNNNNNNNNNNNNNYNNNNYNNN", "YNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNYNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN", "YNNYNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNNN", "NNNNYNNNNNNNNNNYYNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNYNNNNYNYNNNYNNNNYNNNNNNNYNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNYNN", "NNYNNYYYNNNNNNNNNNNNNNYNNNYNNNNNNYNNNNNNNYNNN", "NNNYNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNYYNNYNYNNNN", "YNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNYNYNNNN", "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN"}
//	) << ": 35" << std::endl;

	//SentenceCapitalizerInator a;
	//std::cout << a.fixCaps("example four. the long fourth example. a. b. c. d.") << std::endl;
	
	PerfectSequences a;
	std::cout << a.fixIt({1000000,1,1,1,1,2}) << " yes" << std::endl;
	std::cout << a.fixIt({1,4,2,4,2,4} ) << " no" << std::endl;
	std::cout << a.fixIt({1,2,3}) << " no" << std::endl;
	std::cout << a.fixIt({1,3,4}) << " yes" << std::endl;
	std::cout << a.fixIt({8}) << " yes" << std::endl;
	std::cout << a.fixIt({2,0,2}) << " no" << std::endl;

	
	//std::cout << a.fixIt() << "yes" << std::endl;


  return 0;
}