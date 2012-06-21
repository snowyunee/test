#include <iostream>
#include "l3.h"

int main()
{
  RectangleArea a;
  std::cout << a.minimumQueries( {"YNY", "NYN", "YNY"}) << ": 1" << std::endl;
	std::cout << a.minimumQueries( 
	  {"NNYYYNN", "NNNNNYN", "YYNNNNY", "NNNYNNN", "YYNNNNY"}
	  ) << ": 2" << std::endl;

	std::cout << a.minimumQueries( 
		//{"NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNN"}	
		 // ) << ": 35" << std::endl;

	//{"NNYNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYNYNNYNNYNNNNNNNNNNNYNNYYNYNNNNNNYYNYNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNYNYNNNYYN", "NNNNYNYNNYNNYNNNNNNNNNNNYNNYYNYNNNNNNYYNYNNNNNNN"}
	//	  ) << ": 31" << std::endl;
	

				{"NNNNNNNNNNNNNNNNNNNNYYNNNNNNYNNNNNNNNNNNNNNYN", "NNNNNNNNNNNNYNNNNNNYNNNNYYNNYNNYNNNNNNNNNNNYN", "NNNNNNNNNNNNNNYNNYNNNYNNNNNNYNNNNNNNNNNNNNNYN", "YNNYNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNNNNYNNNN", "NNNNNNNNYNNNNNYNNNNYNNNNNNNNNNNYNNNNNNNNNNNYN", "NNNYNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNN", "NNNNYNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNYNNNN", "YNNYYNNNNNYNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNYNNNNNNNNYNNNYNNNNNYYNNNNNYNNNNY", "NNNNNNNNNNNNNNYNNNNNYNNNYYNNNNNNNNNNNNNNNNNYN", "NNNYNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN", "NNNNNNNNYNNNNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNN", "NNNNNYYYNYNNNYNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNY", "NNYNNYYNNYNNNYNNNNYNNNYNNNYNNNNNYNNNNNNYNYNNY", "NNNNNNNNNNNNNNNNNYNNNNNNNYNNYNNNNNNNNNNNNNNNN", "YNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNN", "YNNNNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNYNN", "NNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNNNNYYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNYNYNNNYNNNNYNNNNNNNNNNNNNNNNNYNNNNYNNN", "YNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNYNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN", "YNNYNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNNN", "NNNNYNNNNNNNNNNYYNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNYNNNNYNYNNNYNNNNYNNNNNNNYNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNYNN", "NNYNNYYYNNNNNNNNNNNNNNYNNNYNNNNNNYNNNNNNNYNNN", "NNNYNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNYYNNYNYNNNN", "YNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNYNYNNNN", "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN"}
	) << ": 35" << std::endl;
  return 0;
}
