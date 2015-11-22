#include "point-line.h"
#include <iostream>
using namespace std;

const int size = 20;

void printGraph()
{
	for(int i = 0; i < size + 1; ++i)
	{
		for(int j = 0; j < size + 1; ++j)
		{
			if(i == size/2)
				cout << "+ ";
			else if (j == size/2)
				cout << "+ ";
			else
				cout << ". ";
		}
		
		cout << endl;
	}
}



int main()
{
	printGraph();
	return 0;
}

