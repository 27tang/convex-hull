#include "point-line.h"
#include <cstring>
#include <time.h>

class BruteForce
{
	public:
		BruteForce();
		~BruteForce();

		int readInPoints();
		int displayForGrapher();
        int displayProcessingTime();
		int createLine(Line * &, int, int);	
		int findConvexHull();
	
	private:
		int setSize;
        int convexSetSize;
		Point ** pointSet;
        clock_t cycles;


};

BruteForce::BruteForce()
{
    convexSetSize = 0;
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

int BruteForce::createLine(Line * & line, int i, int j)
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
	else{cout << "ERROR PROCESSING POINTS!!\n"; exit(0);}
}

int BruteForce::findConvexHull()
{
    cycles = clock();
	for (int i = 0; i < setSize; i++)
	{
		for (int j = i+1; j < setSize; j++)
		{
			Line * line = NULL;
			
			createLine(line, i, j);

			int z = 1;
			int sideOf = line->whichSideOfLine(*pointSet[0]);

			sideOf = 0;
			for (int k = 0; k < setSize; k++)
			{
				int sideOf2 = line->whichSideOfLine(*pointSet[k]);
				if (sideOf2 != 0 && sideOf == 0)
					sideOf = sideOf2;
				if (sideOf != 0 && (sideOf2*sideOf) < 0)
				{
					break;
				} 
				if (k == (setSize-1))
				{
                    if(pointSet[i]->checkAndSetFlag()==1)
                      convexSetSize++;
                    
                    if(pointSet[j]->checkAndSetFlag()==1)
                      convexSetSize++;
				}
			}
		}
	}

    cycles = clock() - cycles;

}
int BruteForce::displayProcessingTime()
{
  cout << "Cycles: " << cycles << endl;
}


int BruteForce::displayForGrapher()
{
    cout << setSize << endl;
	for(int i = 0; i< setSize; ++i)
	{
		pointSet[i]->fileFormatDisplay(); 
	}

    cout  << convexSetSize << endl;
    for(int i = 0; i < setSize; ++i)
    {
        if(pointSet[i]->checkFlag())
          pointSet[i]->fileFormatDisplay();
    }
}


int main(int argc, char * argv[])
{
    
    BruteForce bruteForce;
    bruteForce.readInPoints();
	bruteForce.findConvexHull();
    if(argc > 1 && strcmp(argv[1], "-g") == 0)
    {
      bruteForce.displayForGrapher();
    }
    else
    {
      cout << "Processing Time: " ;
      bruteForce.displayProcessingTime();
    }

	return 0;
}

