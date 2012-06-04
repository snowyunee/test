
#include <vector>
#include <iostream>
#include "crouching_amoebas.h"


int main(int argc, const char *argv[])
{
	CrouchingAmoebas a;
  std::cout << a.count( {0,0}, {0,1}, 1, 1) << " : Returns: 2" << std::endl;
  //std::cout << a.count( {0,1,2}, {1,2,0}, 1, 1) << " : Returns: 2" << std::endl;
  //std::cout << a.count( {0,1,2}, {1,2,0}, 1, 2) << " : Returns: 3" << std::endl;
  //std::cout << a.count( {0,0,3,3}, {0,3,0,3}, 2, 4) << " : Returns: 4" << std::endl;
  //std::cout << a.count( {-1000000000,1000000000}, {-1000000000,1000000000}, 1, 15) << " : Returns: 1" << std::endl;
  //
  //std::cout << a.count( {342309707, 194739121, -861097383, -628913534, 403532428, 457067342, 723807664, -192788875, 913672280, 576164955, -219921316, -23378967, -915969195, -645967605, -745831133, 570993459, 736978536, -561034283, 247615242, -180265751, -900687691, -996184212, -9276073, 201277919, 840383906, 604608198, 700731277, 121346858, 571374804, 711351576}, {377240171, -41533989, 290405490, -286105999, -81964450, 68450042, -990289548, 776639452, 397113306, -944710241, 942710557, 867080052, -989746517, -748912215, 245730907, 438197301, -857930528, -166245070, -938165671, -740536483, 634300101, -84370280, 609244295, 980002920, 54167270, -450778505, 187186319, 512112916, 963225105, -151882834}, 112939892, 15) << " << : return : 1" << std::endl;
    	
//	std::cout << a.count( {64120008, -43727822, 44587005, -38714430, 38539936, -45580680, -42635928, -33334956, -36932589, -20080759, 3295777, -77661330, -78036681, -44286323, 58139001, 50120815, -76149149, -77218067, 24818917, -7592743, 75007548, -39706017, -87951323, 90762113, 90501529, 97205443, -2509522, -50822795, -80131170, -9745332}, {7308966, -33079962, -59222489, 1242129, -90454636, 14837515, -42009250, -59958946, -57621282, 13367922, -22242025, -31662484, -55313165, 33486514, -32023572, 19686500, -24802685, 12421376, 50113207, 38271158, 33033864, -63218453, -84298107, 36736237, 73950778, -98462665, -660305, -14766330, 26043138, 82689769}, 487744930, 15) << " : return : 30 " << std::endl;

  //std::cout << a.count( {4, -10, 0, -2, 1, 9, 9, 5, -6, -5, -10, -2, -7, 3, 0, -1, 6, -9, -3, 10, 2, -8, -5, 8, -1, -9, 7, -7, -3, 7}, {-7, 6, -1, -10, -7, -4, 10, 0, -1, -10, 2, 8, 10, -2, -5, -5, 9, -9, 5, -4, 2, 6, -7, 0, -7, 3, -1, 8, -9, 8}, 10, 15) << " : return : 18" << std::endl;
  return 0;
}

