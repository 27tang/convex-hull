#include "point-line.h"
#include <iostream>
using namespace std;
/*
 *
 * Grapher utility
 *
 * usage:
 *        ./grapher [size of graph] < [text file created by point-set-generator]
*/

class Grapher
{
 	public:
    	Grapher();
        Grapher(int size);  //constructor specifying graph size
   	 	~Grapher();

    	void readInPoints();
		int checkIfPointInSet(const Point & point);
		void printGraph();
        
        int checkIfPointInConvexSet(const Point & point);

	private:
        int graphSize;
		int setSize;
        int convexSetSize;
		Point ** pointSet;
        Point ** convexSet;

};

Grapher::Grapher()
{
    convexSetSize = 0;
	setSize = 0;
	pointSet = NULL;
    convexSet = NULL;
}

Grapher::Grapher(int size)
{
  convexSetSize = 0;
  setSize = 0;
  pointSet = NULL;
  graphSize = size;
  convexSet = NULL;
}

Grapher::~Grapher(){

}

void Grapher::readInPoints()
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

  
  cin >> convexSetSize; cin.ignore();
  
  convexSet = new Point * [convexSetSize];

  for(int i = 0; i < convexSetSize; ++i)
  {
      int x = 0;
      int y = 0;
      cin >> x; cin.ignore();
      cin >> y; cin.ignore();
      convexSet[i] = new Point(x, y);
  }

}

int Grapher::checkIfPointInSet(const Point & point)
{
	for(int i = 0; i < setSize; ++i)
	{
		if(pointSet[i]->compareX(point)==0 && pointSet[i]->compareY(point)==0)
			return 1;
	}

	return 0;

}

int Grapher::checkIfPointInConvexSet(const Point & point)
{
	for(int i = 0; i < convexSetSize; ++i)
	{
		if(convexSet[i]->compareX(point)==0 && convexSet[i]->compareY(point)==0)
			return 1;
	}

	return 0;

}


void Grapher::printGraph()
{

    Point * pointSetGraphed[setSize];
    int printCursor = 0;
    int count = 0;
    for(int i = graphSize; i > -(graphSize + 1); --i)
	{
        int foundCount = 0;
		for(int j = -graphSize; j < graphSize + 1; ++j)
		{
            Point point(j, i);

            if(checkIfPointInConvexSet(point))
            {
                pointSetGraphed[count] = new Point(point);
                pointSetGraphed[count]->checkAndSetFlag();
                ++count;
                ++foundCount;
				cout << "X ";

            }
            else if(checkIfPointInSet(point))
            {
                pointSetGraphed[count] = new Point(point);
                ++count;
                ++foundCount;
				cout << "0 ";
            }
			else if(i == 0)
				cout << "+ ";
			else if (j == 0)
				cout << "+ ";
			else
				cout << "  ";
		}
        for(int k = 0; k < foundCount; ++k)
        {
          if(pointSetGraphed[printCursor]->checkFlag())
          {
            cout << "["; pointSetGraphed[printCursor]->display();
            cout << "]";
          }
          else
            pointSetGraphed[printCursor]->display();
          cout << " ";
          delete pointSetGraphed[printCursor];
          ++printCursor;
        }
		cout << endl;
	}


}


int main(int argc, char * argv[])
{
    int graphSize = atoi(argv[1]); 
	Grapher grapher(graphSize);
	grapher.readInPoints();
	grapher.printGraph();
cout << endl << endl;

	return 0;
}
