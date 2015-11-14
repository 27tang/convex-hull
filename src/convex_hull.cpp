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

Point::Point(Point copySource)
{
  this->x = copySource.x;
  this->y = copySource.y;
}

void Point::display()
{
  cout << "X Coordinate: " << x << endl;
  cout << "Y Coordinate: " << y << endl;
}

Line::Line()
{
  points[0] = NULL;
  points[1] = NULL;
}

Line::Line(Point p1, Point p2)
{
  points[0] = new Point(p1);
  points[1] = new Point(p2);
}




BruteForceConvexHull::BruteForceConvexHull()
{

}


