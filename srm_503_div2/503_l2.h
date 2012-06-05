#include <vector>
#include <algorithm>

class ToastXToast
{
 public:
  int bake(std::vector<int> undertoasted, std::vector<int> overtoasted)
  {
    if(undertoasted.size() == 0 || overtoasted.size() == 0) return -1;

    std::sort(undertoasted.begin(), undertoasted.end());
    std::sort(overtoasted.begin(), overtoasted.end());
    if(*std::max_element(overtoasted.begin(), overtoasted.end()) <=
       *std::min_element(undertoasted.begin(), undertoasted.end()))
      return -1;
    if(*std::min_element(overtoasted.begin(), overtoasted.end()) <=
       *std::min_element(undertoasted.begin(), undertoasted.end()))
      return -1;
    if(*std::max_element(undertoasted.begin(), undertoasted.end()) <
       *std::min_element(overtoasted.begin(), overtoasted.end()))
      return 1;
    return 2;
  }
};
