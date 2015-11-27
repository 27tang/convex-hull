#include "point-line.h"
#include <cstring>
#include <time.h>

class QuickHull
{
  public:
    QuickHull();
    ~QuickHull();
    
    void readInPoints();
    void displayForGrapher();
    void displayProcessingTime();

    void createLine(Line *& line, int i, int j);
    void findConvexHull();

  private:

    Point ** pointSet; //dynamic array of Points
    int setSize;
    int convexSetSize; 

};

QuickHull::QuickHull()
{
    pointSet = NULL;
    setSize = 0;
    convexSetSize = 0;
    clock_t cycles;
}

QuickHull::~QuickHull()
{

}

void QuickHull::readInPoints()
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

void QuickHull::createLine(Line *& line, int i, int j)
{

    int relation = pointSet[i]->pointRelation(*pointSet[j]);
    
    if (relation == 1){
        line = new VerticalLine(*pointSet[i], *pointSet[j]);
    }
    else if (relation == 2){
        line = new HorizontalLine(*pointSet[i], *pointSet[j]);
    }
    else if (relation == 0){
        line = new SkewLine(*pointSet[i], *pointSet[j]);
    }
    else{cerr << "ERROR PROCESSING POINTS!!\n"; exit(0);}
}


void QuickHull::findConvexHull()
{


}


int main(int argc, char * argv[])
{
    QuickHull quickHull;
    quickHull.readInPoints();
    quickHull.findConvexHull();

    if(argc > 1 && strcmp(argv[1], "-g") == 0)
      //quickHull.displayForGrapher();
    //else
      //quickHull.displayProcessingTime();
      //
      //
  return 0;
}
