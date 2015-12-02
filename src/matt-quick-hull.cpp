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
    
    int quickHullTop(Point ** pArray, Point *& middle, int, int, int indexOfMid);
    int quickHullBottom(Point ** pArray, Point *& middle, int, int, int indexOfMid);
	int findHighest(Line * &, Point * &, int, int);
	int findLowest(Line *&, Point * &, int, int);
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

		
	pointSet[end]->checkAndSetFlag();
	convexSetSize++;

	pointSet[0]->checkAndSetFlag();
	convexSetSize++;
		
	int indexOfTop = 1;
	int indexOfBottom = 1;

	Point * highest = pointSet[0];
	/*
	for (int i = 2; i < setSize -1; ++i)
	{
		if (highest->compareY(*pointSet[i]) == 1)
		{
			highest = pointSet[i];
			indexOfTop = i;
		}
	}
	*/
	indexOfTop = findHighest(line, highest, 0, setSize-1);
	
	Point * lowest = pointSet[0];
	/*
	for (int i = 2; i< setSize-1; ++i)
	{
		if (lowest->compareY(*pointSet[i]) == -1)
		{
			lowest = pointSet[i];
			indexOfBottom = i;
		}
	}*/

	indexOfBottom = findLowest(line, lowest, 0, setSize-1);
	
	//cout << "Highest was calculated to be...\n";
	//highest->display(); 
	//cout << endl;
	if(pointSet[indexOfTop]->checkAndSetFlag()==1)
	convexSetSize++;

	//cout << "Lowest was calculated to be...\n";
	//lowest->display();
	//cout << endl;
	if(pointSet[indexOfBottom]->checkAndSetFlag()== 1)
	convexSetSize++;
	
	Line * topLine = NULL;
	Line * botLine = NULL;

	//createLine(topLine, pointSet[0], highest);
	//createLine(botLine, pointSet[end], lowest);
	
	quickHullTop(pointSet, highest, 0, end, indexOfTop);
	quickHullBottom(pointSet, lowest, 0, end, indexOfBottom);
 
	cycles = clock() - cycles; 
	return;

}

//p1 and p2 are indexes of the points of the line passed in
int QuickHull:: quickHullTop(Point ** pArray,Point *& middle, int index1,
							 int index2, int indexOfMid)
{
	Line * left = NULL;
	Line * right = NULL;
	bool leftFlag = true;
	bool rightFlag = true;

	//this is the case where there are no points between them.
	if (indexOfMid - index1 <=1 && index2-indexOfMid <=1) return 0;
	
	createLine(left, pointSet[index1], middle);
	createLine(right, middle, pointSet[index2]);
	
	Point * highLeft = pointSet[index1];
	int topLeft = findHighest(left, highLeft, index1, indexOfMid);
	if (index1 == topLeft) leftFlag = false;

	Point * highRight = pointSet[indexOfMid];
	int topRight = findHighest(right, highRight, indexOfMid, index2);
	if (indexOfMid == topRight) rightFlag = false;

	if (pointSet[topLeft]->checkAndSetFlag() == 1)
		convexSetSize++;
	if (pointSet[topRight]->checkAndSetFlag() == 1)
		convexSetSize++;

	if(leftFlag)
		quickHullTop(pointSet, highLeft, index1, indexOfMid, topLeft);

	if(rightFlag)
		quickHullTop(pointSet, highRight, indexOfMid, index2, topRight);

		
	return 2;	
}

int QuickHull::findHighest(Line * & line, Point *& highest, int leftBound, int rightBound)
{	
	int indexOfTop = leftBound;
	highest = pointSet[indexOfTop];
	double distance = 0;
	double distance1 = 0;	
	for (int i = leftBound; i< rightBound; i++)
	{
		distance1 = line->whichSideOfLine(*pointSet[i]);
		if(distance1 > 0 && distance1 > distance)
		{
			distance = distance1;
			indexOfTop = i;
			highest = pointSet[i];
		}
	}
	return indexOfTop;
}

int QuickHull::findLowest(Line *& line, Point * & lowest, int leftBound, int rightBound)
{	
	int indexOfBottom = leftBound;
	lowest = pointSet[indexOfBottom];
	double distance = 0;
	double distance1 = 0;	
	for (int i = leftBound; i< rightBound; i++)
	{
		distance1 = line->whichSideOfLine(*pointSet[i]);
		if(distance1 < 0 && distance1 < distance)
		{
			distance = distance1;
			indexOfBottom = i;
			lowest = pointSet[i];
		}
	}

	return indexOfBottom;
}
int QuickHull::quickHullBottom(Point ** pArray, Point *& middle, int index1,
								 int index2, int indexOfMid)
{
	
	Line * left = NULL;
	Line * right = NULL;
	bool leftFlag = true;
	bool rightFlag = true;

	if (indexOfMid - index1 <=1 && index2-indexOfMid <=1) return 0;

	createLine(left, pointSet[index1], middle);
	createLine(right, middle, pointSet[index2]);
	
	Point * bottomLeft = pointSet[index1];
	int lowLeftIndex = findLowest(left, bottomLeft, index1, indexOfMid);
	if(lowLeftIndex == index1) leftFlag = false;

	Point * bottomRight = pointSet[indexOfMid];
	int lowRightIndex = findLowest(right, bottomRight, indexOfMid, index2);
	if (lowRightIndex == indexOfMid) rightFlag = false;

	if (pointSet[lowLeftIndex]->checkAndSetFlag() == 1)
		convexSetSize++;
	if (pointSet[lowRightIndex]->checkAndSetFlag() == 1)
		convexSetSize++;
	
	if(leftFlag)	
	quickHullBottom(pointSet, bottomLeft, index1, indexOfMid, lowLeftIndex);
	
	if(rightFlag)
	quickHullBottom(pointSet, bottomRight, indexOfMid, index2, lowRightIndex);
  return 3;
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

void QuickHull::displayProcessingTime()
{
  cout << "Cycles: " << cycles << endl;
  cout << "Time(clicks): " << ((float) cycles)/CLOCKS_PER_SEC << endl;
 
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
    else
    	quickHull.displayProcessingTime();
      
      
  return 0;
}
