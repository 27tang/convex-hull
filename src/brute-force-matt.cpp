#include "point-line.h"
//Matt's version of BruteForce
class BruteMatt
{
	public:
		BruteMatt();
		~BruteMatt();

		int readInPoints();
		int displayPointSet();
		int createLine(Line * &, int, int);	
		int findConvexHull();
	
	private:
		int setSize;
		Point ** pointSet;


};

BruteMatt::BruteMatt()
{
	setSize = 0;
	pointSet = NULL;
}

BruteMatt::~BruteMatt()
{

}

int BruteMatt::readInPoints()
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

int BruteMatt::displayPointSet()
{
	for(int i = 0; i< setSize; ++i)
	{
		pointSet[i]->display(); cout << endl;
	}
}


int BruteMatt::createLine(Line * & line, int i, int j)
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

int BruteMatt::findConvexHull()
{
	for (int i = 0; i < setSize; i++)
	{
		for (int j = i+1; j < setSize-1; j++)
		{
			Line * line = NULL;
			
			//point relation returns 1 if X's are the same
			//						 2 if Y's are the same
			//						 0 if it's a skew line
			createLine(line, i, j);

			int sideOf = line->whichSideOfLine(*pointSet[j+1]);
			for (int k = 0; k < setSize; k++)
			{
				int sideOf2 = line->whichSideOfLine(*pointSet[k]);
				if (sideOf2 != 0 && (sideOf2*sideOf) < 0)
				{
					break;
				} 
				if (k == setSize-1)
				{
					//cout << "------Found part of Convex Hull------\n";
					line->display();
				}
			}
		}
	}	

}

int main()
{
	cout << "Running Matt's brute force Convex Hull..." << endl;
	BruteMatt bruteMatt;
	bruteMatt.readInPoints();
	bruteMatt.displayPointSet();
	
	bruteMatt.findConvexHull();

	return 0;
}

