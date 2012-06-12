
#include <vector>
#include <algorithm>

class ComparerInator
{
 public:
  int makeProgram(std::vector<int> A, std::vector<int> B, std::vector<int> wanted)
  {
    if(A == wanted ||
       B == wanted)
      return 1;

    auto min(A);
    std::transform(A.begin(), A.end(), B.begin(), min.begin(), [](int a, int b) { return std::min(a, b); });
    if(min == wanted)
      return 7;

    auto max(A);
    std::transform(A.begin(), A.end(), B.begin(), max.begin(), [](int a, int b) { return std::max(a, b); });
    if(max == wanted)
      return 7;

    return -1;
  }
};
