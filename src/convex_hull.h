#include <iostream>
using namespace std;


class Point
{
  public:
    Point();
    Point(int x, int y);    //constructure with arguments
    Point(const Point & copySource);  //copy constructor
    int multX(int toMultiply);
    int multY(int toMultiply);

    ~Point();               //destructor

    int compareX(const Point & toCompare);
    int compareY(const Point & toCompare);
    void display();

  private:
    int x;
    int y;
};

class Line
{
  public:
    Line();
    Line(const Point & p1, const Point & p2);
    ~Line();

    virtual int whichSideOfLine(Point point) = 0;
    virtual void display() = 0;

  protected:
    Point * points[2];

};

class VerticalLine: public Line
{
  public:
    VerticalLine();
    VerticalLine(Point p1, Point p2);
    ~VerticalLine();
    
    virtual int whichSideOfLine(Point point);
    virtual void display();
  private:

};

class HorizontalLine: public Line
{
  public:
    HorizontalLine();
    HorizontalLine(Point p1, Point p2);
    ~HorizontalLine();

    virtual int whichSideOfLine(Point point);
    virtual void display();

  private:

};

class SkewLine: public Line
{
  public:
    SkewLine();
    SkewLine(Point p1, Point p2);
    ~SkewLine();

    virtual int whichSideOfLine(Point point);
    virtual void display();

  private:
      int a;
      int b;
      int c;
};

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
