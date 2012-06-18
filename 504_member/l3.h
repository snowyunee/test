#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <list>
#include <assert.h>

class RectangleArea
{
 public:
  int minimumQueries(std::vector<std::string> known)
  {
    std::list<std::pair<int,int> > unknown_points;
    for(auto i=known.begin(); i!=known.end(); ++i)
    {
      for(auto j=i->begin(); j!=i->end(); ++j)
      {
        if(*j == 'Y')
          unknown_points.push_back(std::make_pair(i-known.begin(), j-i->begin()));
      }
    }

    int r = 0;
    do
    {
      check(unknown_points, known);
      std::pair<int, int> query_point = (unknown_points.front());
      unknown_points.pop_front();
      ++r;
      known[query_point.first][query_point.second] = 'Y';
    }
    while(0 < unknown_points.size());
    return r;
  }

  void check(std::list<std::pair<int,int> >& unknown_points, std::vector<std::string>& known)
  {
    bool is_added = true;
    while(is_added == true)
    {
      for(auto i=0; i<known.size(); ++i)
      {
        for(auto j=0; j<known[0].size(); ++j)
        {
          if(known[i][j] == 'Y') 
          {
            is_added = set_known(i, j, known, unknown_points);
          }
        }
      }
    }
  }

  bool set_known(int y, int x, std::vector<std::string>& known, std::list<std::pair<int,int> >& unknown_points)
  {
    std::list<int> y_list;
    for(int j=0; j<known[0].size(); ++j)
    {
      if(j==x) continue;
      if(known[y][j] == 'Y') y_list.push_back(j);
    }
    std::list<int> x_list;
    for(int j=0; j<known[0].size(); ++j)
    {
      if(j==x) continue;
      if(known[j][x] == 'Y') x_list.push_back(j);
    }
    std::cout << "x_list" << x_list.size() << ", y" << y_list.size() << std::endl;
    for(int i=0; i<x_list.size(); ++i)
    {
      for(int j=0; j<y_list.size(); ++j)
      {
        if(known[j][i] != 'Y')
        {
          std::cout << "j" << j << ", i" << i << std::endl;
          known[j][i] == 'Y';
          bool is_erase = false;
          for(auto k=unknown_points.begin(); k!=unknown_points.end(); ++k)
          {
            if(k->first == j && k->second == i)
            {
              unknown_points.erase(k);
              is_erase = true;
              break;
            }
          }
          assert(is_erase);
          return true;
        }
      }
    }
    return false;
  }

};
