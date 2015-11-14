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

Point::Point(const Point & copySource)
{
  this->x = copySource.x;
  this->y = copySource.y;
}

Point::~Point()
{

}

int Point::compareX(const Point & toCompare)
{
  if(this->x > toCompare.x)
    return -1;
  if(this->x < toCompare.x)
    return 1;
  else return 0;
}

int Point::compareY(const Point & toCompare)
{
  if(this->y > toCompare.y)
    return -1;
  if(this->y < toCompare.y)
    return 1;
  else return 0;
}

int Point::multX(int toMultiply)
{
  return x * toMultiply;
}

int Point::multY(int toMultiply)
{
  return y * toMultiply;
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

Line::Line(const Point & p1, const Point &p2)
{
  points[0] = new Point(p1);
  points[1] = new Point(p2);
}

Line::~Line()
{

}

int Line::whichSideOfLine(Point point){}  //pure virtual

void Line::display(){}

VerticalLine::VerticalLine():Line(){}

VerticalLine::VerticalLine(Point p1, Point p2):Line(p1,p2){}

VerticalLine::~VerticalLine()
{}

//returns -1 if to the left, 1 if to the right, 0 if on
int VerticalLine::whichSideOfLine(Point point)
{

  return points[0]->compareX(point);
}

void VerticalLine::display()
{
  cout << "Displaying Vertical Line" << endl;
  cout << "p1: "; points[0]->display();
  cout << "p2: "; points[1]->display();
}


HorizontalLine::HorizontalLine():Line(){}

HorizontalLine::HorizontalLine(Point p1, Point p2):Line(p1,p2){}

HorizontalLine::~HorizontalLine()
{

}

//returns -1 if under, 1 if above, 0 if on
int HorizontalLine::whichSideOfLine(Point point)
{
     return points[1]->compareY(point);
}

void HorizontalLine::display()
{
  cout << "Displaying Horizontal Line" << endl;
   cout << "p1: "; points[0]->display();
  cout << "p2: "; points[1]->display();


}



SkewLine::SkewLine():Line(){}

SkewLine::SkewLine(Point p1, Point p2):Line(p1,p2){}

SkewLine::~SkewLine()
{

}

//returns -1 if under, 1 if above, 0 if on
int SkewLine::whichSideOfLine(Point point)
{

  //return multY(a) + multX(b) - c;
}

void SkewLine::display()
{
  cout << "Displaying Skew Line" << endl;
   cout << "p1: "; points[0]->display();
  cout << "p2: "; points[1]->display();


}








BruteForceConvexHull::BruteForceConvexHull()
{

}


