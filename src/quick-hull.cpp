#include "point-line.h"
#include <cstring>
#include <time.h>

class QuickHull
{
  public:
    QuickHull();
    ~QuickHull();
    
    void readInPoints();
    void displayProcessingTime();

    void createLine(Line *& line, Point *& p1, Point *& p2);
    void findConvexHull();
    
    int quickHullTop(Point ** pArray, Line *& line, Point *& p1, Point *& p2, int pArraySize);
    int quickHullBottom(Point ** pArray, Line *& line, Point *& p1, Point *& p2, int pArraySize);

	void displayForGrapher();

  private:

    Point ** pointSet; //dynamic array of Points
    int setSize;
    int convexSetSize; 
    clock_t cycles;

};

QuickHull::QuickHull()
{
    pointSet = NULL;
    setSize = 0;
    convexSetSize = 0;
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

void QuickHull::createLine(Line *& line, Point *& p1, Point *& p2)
{

    int relation = p1->pointRelation(*p2);
    if (relation == 1)
        line = new VerticalLine(*p1, *p2);
    else if (relation == 2)
        line = new HorizontalLine(*p1, *p2);
    else if (relation == 0)
        line = new SkewLine(*p1, *p2);
    else
    {
      cerr << "ERROR PROCESSING POINTS!!\n"; 
      exit(0);
    }
}


void QuickHull::findConvexHull()
{

  cycles = clock();
  //if set size is less than 4, then all points are in convex set
  if(setSize < 4)
  {
    for(int i = 0; i < setSize; ++i)
    {
      if(pointSet[i]->checkAndSetFlag() == 1)
        convexSetSize++;
    }
    return;
  }

  int end = setSize-1;
  Line * line = NULL;
  createLine(line, pointSet[0], pointSet[end]);

  //adding extrema to convex set
  if(pointSet[0]->checkAndSetFlag() == 1)
    convexSetSize++;
  if(pointSet[end]->checkAndSetFlag() == 1)
    convexSetSize++;
  
  int topCount = 0;
  int botCount = 0;
  Point * topSet[setSize-2];
  Point * botSet[setSize-2];

  for(int i = 1; i < setSize-1; ++i)
  {
    if(line->whichSideOfLine(*pointSet[i]) > 0)
    {
      topSet[topCount] = pointSet[i];
      topCount++;
    }
    else if(line->whichSideOfLine(*pointSet[i]) < 0)
    {
      botSet[botCount] = pointSet[i];
      botCount++;
    }
   }

  
    quickHullTop(topSet, line, pointSet[0], pointSet[end], topCount);
    quickHullBottom(botSet, line, pointSet[0], pointSet[end],  botCount);

    cycles = clock() - cycles;

}

//p1 and p2 are indexes of the points of the line passed in
int QuickHull:: quickHullTop(Point ** pArray, Line *& line, Point *& p1, Point *& p2, int pArraySize)
{

  //if number of points to evaluate is 0, we're done
  if(pArraySize == 0)
    return 0;

  //if number of points to evaluate is 1, then the point is in the convex set
  if(pArraySize == 1)
  {
    if(pArray[0]->checkAndSetFlag() == 1)
        convexSetSize++;
    return 1;
  }

  double maxDist = 0;
  int maxDex = 0;
  double dist = 0;
  
  //finding point farthest from line
  for(int i = 0; i < pArraySize; ++i)
  {     
      dist = abs(line->distanceFromLine(*pArray[i]));
      if(dist > maxDist)
      {
        maxDist = dist;
        maxDex = i;
      }
  }

  if(pArray[maxDex]->checkAndSetFlag() == 1)
    convexSetSize++;

  int leftCount = 0;
  int rightCount = 0;
  Point * leftSet[pArraySize-2];
  Point * rightSet[pArraySize-2];
  Line * leftLine;
  Line * rightLine;
  createLine(leftLine, p1, pArray[maxDex]);
  createLine(rightLine, pArray[maxDex], p2);

  for(int i = 0; i < pArraySize; ++i)
  {
    if(leftLine->whichSideOfLine(*pArray[i]) > 0)
    {
      leftSet[leftCount] = pArray[i];
      leftCount++;
    }
    else if(rightLine->whichSideOfLine(*pArray[i]) > 0)
    {
      rightSet[rightCount] = pArray[i];
      rightCount++;
    }
  }

  quickHullTop(leftSet, leftLine, p1, pArray[maxDex], leftCount);
  quickHullTop(rightSet, rightLine, pArray[maxDex], p2, rightCount);

  return 3;
}

int QuickHull::quickHullBottom(Point ** pArray, Line *& line, Point *& p1, Point *& p2, int pArraySize)
{
  //if number of points to evaluate is 0, we're done
  if(pArraySize == 0)
    return 0;

  //if number of points to evaluate is 1, then the point is in the convex set
  if(pArraySize == 1)
  {
    if(pArray[0]->checkAndSetFlag() == 1)
        convexSetSize++;
    return 1;
  }

  double maxDist = 0;
  int maxDex = 0;
  double dist = 0;
  
  //finding point farthest from line
  for(int i = 0; i < pArraySize; ++i)
  {     
      dist = abs(line->distanceFromLine(*pArray[i]));
      if(dist > maxDist)
      {
        maxDist = dist;
        maxDex = i;
      }
  }

  if(pArray[maxDex]->checkAndSetFlag() == 1)
    convexSetSize++;

  int leftCount = 0;
  int rightCount = 0;
  Point * leftSet[pArraySize-2];
  Point * rightSet[pArraySize-2];
  Line * leftLine;
  Line * rightLine;
  createLine(leftLine, p1, pArray[maxDex]);
  createLine(rightLine, pArray[maxDex], p2);

  for(int i = 0; i < pArraySize; ++i)
  {
    if(leftLine->whichSideOfLine(*pArray[i]) < 0)
    {
      leftSet[leftCount] = pArray[i];
      leftCount++;
    }
    else if(rightLine->whichSideOfLine(*pArray[i]) < 0)
    {
      rightSet[rightCount] = pArray[i];
      rightCount++;
    }
  }

  quickHullBottom(leftSet, leftLine, p1, pArray[maxDex], leftCount);
  quickHullBottom(rightSet, rightLine, pArray[maxDex], p2, rightCount);

  return 3;
}

void QuickHull::displayProcessingTime()
{
  cout << "Cycles: " << cycles << endl;
  cout << "Time(clicks): " << ((float) cycles)/CLOCKS_PER_SEC << endl;
 
}

void QuickHull::displayForGrapher()
{
    cout << setSize << endl;
	for(int i = 0; i< setSize; ++i)
	{
		pointSet[i]->fileFormatDisplay(); 
	}
//cout << "0----------" << endl;
    cout  << convexSetSize << endl;
    for(int i = 0; i < setSize; ++i)
    {
      //cout << "--" << endl;
        if(pointSet[i]->checkFlag())
          	pointSet[i]->fileFormatDisplay();
    }
}


int main(int argc, char * argv[])
{
    QuickHull quickHull;
    quickHull.readInPoints();
    quickHull.findConvexHull();

    if(argc > 1 && strcmp(argv[1], "-g") == 0)
{
      quickHull.displayForGrapher();
}
    //else
      //quickHull.displayProcessingTime();
      //
      //
  return 0;
}
