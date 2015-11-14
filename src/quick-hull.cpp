#include "point-line.h"

class QuickHull
{
  public:
    QuickHull();
    ~QuickHull();
    
    int readInPoints();


  private:

    Point * pointSet; //dynamic array of Points


};

QuickHull::QuickHull()
{
  pointSet = NULL;
}

QuickHull::~QuickHull()
{

}

int QuickHull::readInPoints()
{

}


int main()
{

  cout << "Running Quick Hull Convex Hull..." << endl;
  return 0;
}
