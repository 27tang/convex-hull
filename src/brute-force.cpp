#include "point-line.h"

class BruteForce
{
  public:
    BruteForce();
    ~BruteForce();
    
    int readInPoints();
    int displayPointSet();

    int findConvexHull();

  private:

    int setSize;
    Point ** pointSet; //dynamic array of Points


};

BruteForce::BruteForce()
{
  setSize = 0;
  pointSet = NULL;
}

BruteForce::~BruteForce()
{

}

int BruteForce::readInPoints()
{
  cin >> setSize; cin.ignore();

  pointSet = new Point * [setSize];

  for(int i = 0; i < setSize; ++i)
  {
    int x = 0;
    int y = 0;
    cin >> x; cin.ignore();
    cin >> y; cin.ignore();
    pointSet[i] = new Point(x, y);
  }

}

int BruteForce::displayPointSet()
{
  for(int i = 0; i < setSize; ++i)
  {
    pointSet[i]->display(); cout << endl;

  }
}

int BruteForce::findConvexHull()
{
  for(int i = 0; i < setSize; ++i)
  {
    for(int j = i+1; j < setSize; ++j)
    {
      Line * line;
//      if(pointSet[i] == pointSet[j])
  //      break;

      if(pointSet[i]->pointRelation(*pointSet[j]) == 0)
      {
        line = new SkewLine(*pointSet[i], *pointSet[j]);
      } else
      if(pointSet[i]->pointRelation(*pointSet[j]) == 1)
      {
        line = new VerticalLine(*pointSet[i], *pointSet[j]);
      }
      else
      {
        line = new HorizontalLine(*pointSet[i], *pointSet[j]);
      }

      int result = 0;
      int previousResult = 0;
      int k = 0;

      while(previousResult == 0)
      {
        previousResult = line->whichSideOfLine(*pointSet[k]);
        ++k;
      }

      int fail = 0;
      for(; k < setSize; ++k)
      {
        result = line->whichSideOfLine(*pointSet[k]);
        if(result * previousResult < 0)
        {
          fail = 1; 
          break;
        }
        previousResult = result;
        
      }

      if(fail == 0)
        line->display();

    }
  }

}

int main()
{

  cout << "Running Brute Force Convex Hull..." << endl;
  BruteForce bruteForcer;
  bruteForcer.readInPoints();
  bruteForcer.displayPointSet();

  bruteForcer.findConvexHull();

  return 0;
}
