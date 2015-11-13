#include "convex_hull.h"


Point::Point()
{
  x = 0;
  y = 0;
}

Point::Point(int x, int y)
{
  this->x = x;
  this->y = y;
}

void Point::display()
{
  cout << "X Coordinate: " << x << endl;
  cout << "Y Coordinate: " << y << endl;
}
/*
Line::Line()
{

}



*/

BruteForceConvexHull::BruteForceConvexHull()
{

}


