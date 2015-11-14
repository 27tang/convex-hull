#include <iostream>
using namespace std;


class Point
{
  public:
    Point();
    Point(int x, int y);    //constructure with arguments
    Point(Point copySource);  //copy constructor
    ~Point();               //destructor

    void display();

  private:
    int x;
    int y;
};

class Line
{
  public:
    Line();
    Line(Point p1, Point p2);
    ~Line();

    virtual int whichSideOfLine(Point point) = 0;
    virtual int display() = 0;

  private:
    Point points[2];

};

class VerticalLine: public Line
{
  public:
    VerticalLine();
    VerticalLine(Point p1, Point p2);
    ~VerticalLine();
    
    virtual int whichSideOfLine(Point point) = 0;
    virtual int display() = 0;
  private:

};

class HorizontalLine: public Line
{
  public:
    HorizontalLine();
    HorizontalLine(Point p1, Point p2);
    ~HorizontalLine();

    virtual int whichSideOfLine(Point point) = 0;
    virtual int display() = 0;

  private:

}



class BruteForceConvexHull
{
  public:
    BruteForceConvexHull();
    ~BruteForceConvexHull();
  private:

};

class QuickHull
{
  public:
    QuickHull();
    ~QuickHull();
  private:


};
