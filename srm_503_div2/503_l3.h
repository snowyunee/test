#include <vector>
#include <map>
#include <math.h>

class KingdomXCitiesandVillagesAnother
{
 public:
  double determineLength(std::vector<int> cityX, std::vector<int> cityY, std::vector<int> villageX, std::vector<int> villageY)
  {
    distance_.clear();
    double result = determineLength_r(cityX, cityY, villageX, villageY);
    return result;
  }

  double determineLength_r(std::vector<int> cityX, std::vector<int> cityY, std::vector<int> villageX, std::vector<int> villageY)
  {
    if(villageX.size() == 0) return 0.0;

    double min_distance = 0.0;
    int min_village_i = -1;
    for(int i=0; i<villageX.size(); ++i)
    {
      for(int city_i=0; city_i<cityX.size(); ++city_i)
      {
        //if(distance_[std::make_pair(i,city_i)] == 0.0)
        {
          double d = sqrt(pow(villageX[i]-cityX[city_i], 2) + pow(villageY[i]-cityY[city_i], 2));
          distance_[std::make_pair(i,city_i)] = d;
          if(min_village_i < 0 || min_distance > d)
          {
            min_village_i = i;
            min_distance = d;
          }
        }
      }
    }

    cityX.push_back(villageX[min_village_i]);
    cityY.push_back(villageY[min_village_i]);
    villageX.erase(villageX.begin() + min_village_i);
    villageY.erase(villageY.begin() + min_village_i);

    return min_distance + determineLength_r(cityX, cityY, villageX, villageY);
  }
 private:
  std::map<std::pair<int,int>, double> distance_;
};
