#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//point-set-generator:
//    utility to generate a random set of points
//  
//    usage: 
//      point-set-generator [size of set to generate] [random num range] [output file name]

int main(int argc, char * argv[])
{

  srand(time(NULL));

  int count = atoi(argv[1]);
  int range = atoi(argv[2]);
  ofstream outFile;
  outFile.open(argv[3]);
  outFile << count << endl;

  for(int i = 0; i < 2*count; ++i)
  {
    outFile << (rand() % (range*2 + 1)) - range << endl;
  }
  outFile.close();

  return 0;
}
