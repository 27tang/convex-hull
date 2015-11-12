#include <iostream>
using namespace std;


class Point
{
  public:
    Point();
    Point(int x, int y);    //constructure with arguments
    ~Point();               //destructor

  private:
    int x;
    int y;
};

class Line
{
  public:
    Line(); 
    ~Line();

  private:
    Point points[2];

};

class VerticalLine: public Line
{
  public:
    VerticalLine();
    ~VerticalLine();

  private:

};

class HorizontalLine: public Line
{
  public:
    HorizontalLine();
    ~HorizontalLine();

  private:

}

