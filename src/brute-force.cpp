#include "point-line.h"

class BruteForce
{
  public:
    BruteForce();
    ~BruteForce();
    
    int readInPoints();


  private:

    Point * pointSet; //dynamic array of Points


};

BruteForce::BruteForce()
{
  pointSet = NULL;
}

BruteForce::~BruteForce()
{

}

int BruteForce::readInPoints()
{

}


int main()
{

  cout << "Running Brute Force Convex Hull..." << endl;
  return 0;
}
