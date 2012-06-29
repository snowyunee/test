#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <list>
#include <assert.h>
#include <set>
#include <queue>
#include <algorithm>

class RectangleArea
{
public:
	//int minimumQueries(std::vector<std::string> known)
	//{
	//	std::set<std::pair<int,int> > unknown_points;
	//	std::set<std::pair<int,int> > known_points;
	//	for(auto i=known.begin(); i!=known.end(); ++i)
	//	{
	//		for(auto j=i->begin(); j!=i->end(); ++j)
	//		{
	//			if(*j == 'Y')
	//				known_points.insert(std::make_pair(i-known.begin(), j-i->begin()));
	//			else
	//				unknown_points.insert(std::make_pair(i-known.begin(), j-i->begin()));
	//		}
	//	}
	//
	//	std::queue<std::pair<int,int> > additional_known_points;
	//	check_all(known_points, unknown_points, additional_known_points);

	//	int r = 0;
	//	while(false == unknown_points.empty());
	//	{
	//		while(false == additional_known_points.empty())
	//		{
	//			std::pair<int, int> add = additional_known_points.front();
	//			additional_known_points.pop();
	//			add_one(add, known_points, unknown_points, additional_known_points);
	//		}

	//		std::pair<int, int> add = *(unknown_points.begin());
	//		unknown_points.erase(unknown_points.begin());
	//		++r;
	//		add_one(add, known_points, unknown_points, additional_known_points);
	//	}
	//	return r;
	//}

	//void check_all(std::set<std::pair<int,int> >& known_points,
	//		std::set<std::pair<int,int> >& unknown_points,
	//		std::queue<std::pair<int,int> >& additional_known_points)
	//{
	//	if(known_points.empty()) return;
	//	for(auto i=known_points.begin(); i!=known_points.end(); ++i)
	//	{
	//		for(auto j=i; j!=known_points.end(); ++j)
	//		{
	//			if(i->first == j->first || i->second == j->second)
	//			   	continue;

	//			std::pair<int, int> point1 = std::make_pair(i->first, j->second);
	//			std::pair<int, int> point2 = std::make_pair(j->first, i->second);
	//			if(known_points.find(point1) != known_points.end() &&
	//				   	known_points.find(point2) == known_points.end())
	//			{
	//				size_t erase_size = unknown_points.erase(point1);
	//				if(erase_size > 0)
	//					additional_known_points.push(point1);
	//			}
	//			else if(known_points.find(point2) != known_points.end() &&
	//					known_points.find(point1) == known_points.end())
	//			{
	//				size_t erase_size = unknown_points.erase(point2);
	//				if(erase_size > 0)
	//					additional_known_points.push(point2);
	//			}

	//		}
	//	} 
	//}

	int minimumQueries(std::vector<std::string> known)
	{
		std::set<std::pair<int,int> > unknown_points;
		std::set<std::pair<int,int> > known_points;
		for(auto i=known.begin(); i!=known.end(); ++i)
		{
			for(auto j=i->begin(); j!=i->end(); ++j)
			{
				if(*j == 'Y')
					known_points.insert(std::make_pair(i-known.begin(), j-i->begin()));
				else
					unknown_points.insert(std::make_pair(i-known.begin(), j-i->begin()));
			}
		}
	
		bool is_optimal = false;
		while(is_optimal == false)
		{
			std::queue<std::pair<int,int> > wast_points;
			is_optimal = !check_wast(known_points);
		}

		print(known_points);
		return (known.size() + known[0].size() - 1 - known_points.size());
	}

	void print(std::set<std::pair<int,int> >& known_points)
	{
	}

	bool check_wast(std::set<std::pair<int,int> >& known_points)
	{
		if(known_points.empty()) return false;

		for(auto i=known_points.begin(); i!=known_points.end(); ++i)
		{
			for(auto j=i; j!=known_points.end(); ++j)
			{
				if(i->first == j->first || i->second == j->second)
				   	continue;

				std::pair<int, int> point1 = std::make_pair(i->first, j->second);
				std::pair<int, int> point2 = std::make_pair(j->first, i->second);
				if(known_points.find(point1) != known_points.end() &&
					   	known_points.find(point2) != known_points.end())
				{
					size_t erase_size = known_points.erase(point1);
					assert(erase_size == 1);
					return true;
				}
			}
		} 

		return false;
	}


};
