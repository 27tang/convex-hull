#include "point-line.h"
//Matt's version of BruteForce
class BruteForce
{
	public:
		BruteForce();
		~BruteForce();

		int readInPoints();
		int displayPointSet();
		int createLine(Line * &, int, int);	
		int findConvexHull();
	
	private:
		int setSize;
        int convexSetSize;
		Point ** pointSet;


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

int BruteForce::displayPointSet()
{
    cout << setSize << endl;

	for(int i = 0; i< setSize; ++i)
	{
		pointSet[i]->fileFormatDisplay(); 
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
	for (int i = 0; i < setSize; i++)
	{
		for (int j = i+1; j < setSize; j++)
		{
			Line * line = NULL;
			
			//						 0 if it's a skew line
			createLine(line, i, j);

			int z = 1;
			int sideOf = line->whichSideOfLine(*pointSet[0]);

			/*
			while (sideOf == 0)
			{
				sideOf= line->whichSideOfLine(*pointSet[z]);
				z++;
			}
			*/
			sideOf = 0;
			//int sideOf = line->whichSideOfLine(*pointSet[j]);
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
					//cout << "------Found part of Convex Hull------\n";
					//line->display();

                    if(pointSet[i]->checkAndSetFlag()==1)
                      convexSetSize++;
                    
                    if(pointSet[j]->checkAndSetFlag()==1)
                      convexSetSize++;
				}
			}
		}
	}

    cout  << convexSetSize << endl;
    for(int i = 0; i < setSize; ++i)
    {
        if(pointSet[i]->checkFlag())
          pointSet[i]->fileFormatDisplay();
    }

}

int main()
{
	BruteForce bruteForce;
	bruteForce.readInPoints();
	bruteForce.displayPointSet();
	
	bruteForce.findConvexHull();

	return 0;
}

