#include "point-line.h"


Point::Point()
{
  x = 0;
  y = 0;
  inConvexSet = 0;
}

Point::Point(int x, int y)
{
  this->x = x;
  this->y = y;
  inConvexSet = 0;
}

Point::Point(const Point & copySource)
{
  this->x = copySource.x;
  this->y = copySource.y;
  this->inConvexSet = copySource.inConvexSet;
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
  return this->x * toMultiply;
}

int Point::multY(int toMultiply)
{
  return this->y * toMultiply;
}


int Point::XmultiplyY(const Point & toMultiply)
{
  return this->x * toMultiply.y;
}


int Point::subtractX(const Point & toSubtract)
{

  return this->x - toSubtract.x;
}

int Point::subtractY(const Point & toSubtract)
{
  return this->y - toSubtract.y;
}


int Point::pointRelation(const Point & toCompare)
{
  if(this->subtractX(toCompare) == 0)
    return 1;
  if(this->subtractY(toCompare) == 0)
    return 2;
  else
    return 0;

}


int Point::checkAndSetFlag()
{
    //returns 0 if flag is already set
    if(inConvexSet)
      return 0;
    else  //else set flag to 1, and return 1
      inConvexSet = 1;
    return 1;
}

int Point::checkFlag()
{
  if(inConvexSet)
    return 1;
  else
    return 0;
}

void Point::display()
{
  cout << "(" << this->x << ", " << this->y << ")";
}

void Point::fileFormatDisplay()
{
  cout << this->x << endl << this->y << endl;
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

int Line::whichSideOfLine(Point &point){}  //pure virtual

int Line::distanceFromLine(Point & point){} //pure virtual

void Line::display(){}

VerticalLine::VerticalLine():Line(){}

VerticalLine::VerticalLine(Point& p1, Point& p2):Line(p1,p2)
{
  if(p1.subtractX(p2) != 0)
  {
    cout << "FATAL ERROR, LINE NOT VERTICAL! exiting..." << endl;
    exit(EXIT_FAILURE);
  }
}

VerticalLine::~VerticalLine()
{}

//returns -1 if to the left, 1 if to the right, 0 if on
int VerticalLine::whichSideOfLine(Point &point)
{

  return points[0]->compareX(point);
}

int VerticalLine::distanceFromLine(Point & point)
{
  return abs(points[1]->subtractX(point));
}

void VerticalLine::display()
{
  cout << "Displaying Vertical Line" << endl;
  cout << "p1: "; points[0]->display(); cout << endl;
  cout << "p2: "; points[1]->display(); cout << endl;
}


HorizontalLine::HorizontalLine():Line(){}

HorizontalLine::HorizontalLine(Point &p1, Point& p2):Line(p1,p2)
{
  if(p1.subtractY(p2) != 0)
  {
    cout << "FATAL ERROR, LINE NOT HORIZONTAL! exiting..." << endl;
    exit(EXIT_FAILURE);
  }

}

HorizontalLine::~HorizontalLine()
{

}

//returns -1 if under, 1 if above, 0 if on
int HorizontalLine::whichSideOfLine(Point &point)
{
     return points[1]->compareY(point);
}

int HorizontalLine::distanceFromLine(Point & point)
{
  return abs(points[1]->subtractY(point));
}

void HorizontalLine::display()
{
  cout << "Displaying Horizontal Line" << endl;
  cout << "p1: "; points[0]->display(); cout << endl;
  cout << "p2: "; points[1]->display(); cout << endl;


}



SkewLine::SkewLine():Line(){}

SkewLine::SkewLine(Point &p1, Point &p2):Line(p1,p2)
{
  //ax + by = c
  //a = y2 - y1, b = x1 - x2, c = x1y1 - y1x2
  
  this->a = p2.subtractY(p1);
  this->b = p1.subtractX(p2);
  this->c = p1.XmultiplyY(p2) - p2.XmultiplyY(p1);
}

SkewLine::~SkewLine()
{

}

//returns -1 if to the left, 1 if right, 0 if on
int SkewLine::whichSideOfLine(Point &point)
{

//  cout << "ax: " << point.multX(a) << endl;
//  cout << "by: " << point.multY(b) << endl;
  return point.multX(a) + point.multY(b) - c;
}

int SkewLine::distanceFromLine(Point & point)
{
  int top = (point.multX(a) + point.multY(b) + c);
  double bot = sqrt(a * a + b * b);
  
  int result = top/bot;
  return result;

}
void SkewLine::display()
{
  cout << "Displaying Skew Line" << endl;
  cout << "p1: "; points[0]->display(); cout << endl;
  cout << "p2: "; points[1]->display(); cout << endl;
//  cout << "a value: " << a << endl;
//  cout << "b value: " << b << endl;
//  cout << "c value: " << c << endl;


}


