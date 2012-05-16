
#include <vector>
#include <algorithm>



class CrouchingAmoebas
{
 public:
  const static long kMaxDistance = 2000000000;
  struct Rect
  {
    Rect()
    {
      left = 0;
      top = 0;
      right = 0;
      bottom = 0;
    }
    Rect(long left_, long top_, long right_, long bottom_)
    {
      left = left_;
      top = top_;
      right = right_;
      bottom = bottom_;
    }
    long Width() { return right - left; }
    long Height() { return bottom - top; }
    void ExtendWithPoint(std::pair<long, long> point)
    {
      left = std::min(left, point.first);
      right = std::max(right, point.first);
      top = std::min(top, point.second);
      bottom = std::max(bottom, point.second);
    }

    long left;
    long top;
    long right;
    long bottom;
  };

  long count(std::vector<long> x, std::vector<long> y, long A, long T)
  {
    std::vector<std::pair<long, long> > p;
    for (size_t i = 0; i < x.size(); ++i) { p.push_back(std::make_pair(x[i], y[i])); }
      
    long max = 0;
    for (auto i = p.begin(); i != p.end(); ++i)
    {
      std::vector<std::pair<long, long> > inner_p;
      inner_p.push_back(*i);
      Rect rect((*i).first, (*i).second, (*i).first, (*i).second);
      int result = count_r(GetRest(i, p), A, T, inner_p, rect);
      std::cout << "result:" << result << std::endl;
      if (max < result)
        max = result;
    }
    return max;
  }
  std::vector<std::pair<long, long> > GetRest(std::vector<std::pair<long, long> >::iterator except_one, std::vector<std::pair<long, long> > array)
  {
    std::vector<std::pair<long, long> > rest;
    for(auto i = array.begin(); i != array.end(); ++i)
    {
      if(i == except_one) continue;
      rest.push_back(*i);
    }
    return rest;
  }
  std::vector<std::pair<long, long> >::iterator GetClosestPoint(Rect rect, std::vector<std::pair<long, long> > p)
  {
    std::vector<std::pair<long, long> >::iterator result = p.end();
    int min_distance = kMaxDistance;
    for(auto i = p.begin(); i != p.end(); ++i)
    {
      int cur_distance = std::min(std::abs(rect.left-i->first), std::abs(rect.right-i->first)) +
                         std::min(std::abs(rect.top-i->second), std::abs(rect.bottom-i->second));

      if (min_distance > cur_distance)
      {
        result = i;
        min_distance = cur_distance;
      }
    }
    //std::cout << "min_distance:" << min_distance << ", (" << result->first << ", " << result->second << ")" << std::endl;
    return result;
  }

  long count_r(std::vector<std::pair<long, long> > p, long A, long T,
               std::vector<std::pair<long, long> > inner_p, Rect cur_rect)
  {
    //std::cout << "p size:" << p.size() << std::endl;
    long max = (long)inner_p.size();
    if (p.size() <= 0) return max;
    if (T <= 0) return max;

    std::vector<std::pair<long, long> >::iterator itr = GetClosestPoint(cur_rect, p);
    Rect new_rect = cur_rect;
    new_rect.ExtendWithPoint(*itr);
    inner_p.push_back(*itr);
    if (new_rect.Width() > A) T -= new_rect.Width() - std::max(cur_rect.Width(), A);
    if (new_rect.Height() > A) T -= new_rect.Height() - std::max(cur_rect.Width(), A);
    
    return count_r(GetRest(itr, p), A, T, inner_p, new_rect);
  }

//  long count_r(const std::vector<long>& x, const std::vector<long>& y, long A, long T,
//              std::vector<long> cur, long cur_index, Rect cur_rect)
//  {
//    long max = cur.size();
//    //prlong(cur);
//    for (auto i = (unsigned int)(cur_index + 1); i < x.size(); ++i)
//    {
//      long new_t;
//      Rect new_rect;
//      std::vector<long> new_cur(cur);
//      new_cur.push_back(i);
//      if (check(x, y, A, T, cur, cur_rect, i, &new_t, &new_rect) == false)
//      {
//        //std::cout << " faild : " << std::endl;
//        //prlong(new_cur);
//        continue;
//      }
//      long new_max = count_r(x, y, A, new_t, new_cur, i, new_rect);
//      if (new_max > max )
//      {
//        max = new_max;
//        prlong(x, y, new_cur, new_rect, A);
//      }
//    }
//    return max;
//  }
//
//  bool check(const std::vector<long>& x, const std::vector<long>& y, long A, long T,
//            const std::vector<long>& cur, Rect cur_rect, long new_index,
//            long* new_t, Rect* new_rect)
//  {
//    if (cur.size() <= 0)
//    {
//      new_rect->left = new_rect->right = x[new_index];
//      new_rect->top = new_rect->bottom = y[new_index];
//    }
//    else
//    {
//      new_rect->left = std::min(x[new_index], cur_rect.left);
//      new_rect->right = std::max(x[new_index], cur_rect.right);
//      new_rect->top = std::min(y[new_index], cur_rect.top);
//      new_rect->bottom = std::max(y[new_index], cur_rect.bottom);
//    }
//    *new_t = T;
//    if (new_rect->Width() > A) *new_t -= new_rect->Width() - std::max(cur_rect.Width(), A);
//    if (new_rect->Height() > A) *new_t -= new_rect->Height() - std::max(cur_rect.Width(), A);
//
//    if (*new_t >= 0)
//      return true;
//    return false;
//  }

  void prlong(const std::vector<long>& temp)
  {
    for (auto i = temp.begin(); i != temp.end(); ++i)
    {
      std::cout << *i << ", ";
    }
    std::cout << std::endl << std::endl;
  }

  void prlong(const std::vector<long>& x, const std::vector<long>& y, const std::vector<long>& temp,
             Rect rect, long A)
  {
    return;
    std::cout << "A : " << A << std::endl;
    std::cout << "rect:" << "(" << rect.left << ", " << rect.top << "), (" << rect.right << ", " << rect.bottom << ")" << std::endl;
    for (auto i = temp.begin(); i != temp.end(); ++i)
    {
      std::cout << "(" << x[*i] << ", " << y[*i] << "), ";
    }
    std::cout << std::endl << std::endl;
  }


private:
  long check_total_count;;
};
