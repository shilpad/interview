/*
 * main.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

struct Point
{
	int x;
	int y;

public:
	Point (int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator < (const Point &p) const
	{
		if (x < p.x && y < p.y)
			return true;
		else
			return false;
	}
};

bool getPaths (int x, int y, list<Point> &lstPoints, map <Point, bool> cache)
{
	if (x < 0 || y < 0)
		return false;

	Point *p = new Point (x, y);
	map <Point, bool>::iterator it = cache.find (*p);
	if (it != cache.end())
		return it->second;

	bool isAtOrigin = ((x == 0) &&  (y == 0));
	bool bSuccess = false;

	if (isAtOrigin || getPaths (x-1, y, lstPoints, cache) || getPaths(x, y-1, lstPoints, cache))
	{
		cout << "Adding points=" << x << "," << y << endl;
		lstPoints.push_back (*p);
		bSuccess = true;
	}

	cache [*p] = bSuccess;

	return bSuccess;
}

int main ()
{
	list <Point> lstPoints;
	map <Point, bool> cache;

	bool bRet = getPaths (1, 1, lstPoints, cache);
	if (bRet == true)
	{
		cout << "Yes !\n";
		for (list<Point>::iterator it = lstPoints.begin(); it != lstPoints.end(); ++it)
			cout << it->x << "," << it->y << endl;
	}
}



