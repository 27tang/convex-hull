#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include "point-line.h"

using namespace std;

//point-set-generator:
//    utility to generate a random set of points--outputs to stdin
//  
//    usage: 
//      point-set-generator [size of set to generate] [random num range]




void quickSortPointsX(Point ** pArray, int lo, int hi);
void quickSortPointsY(Point ** pArray, int lo, int hi);
void tieBreakPoints(Point ** pArray, int size);
void generateSorted(int count, int range);

void generateCircle(int count, int range);
double circleYmaker(int x, int radius);

int main(int argc, char * argv[])
{

  srand(time(NULL));

  int count = atoi(argv[1]);
  int range = atoi(argv[2]);


  if(argc > 3 && strcmp(argv[3], "-s") == 0)
  {

      cout << count << endl;
      generateSorted(count, range);
      return 0;
  }
  else if( argc > 3 && strcmp(argv[3], "-c")==0)
  {
    generateCircle(count, range);
    return 1;
  }

  for(int i = 0; i < 2*count; ++i)
  {

    cout << count << endl;
    cout << (rand() % (range*2 + 1)) - range << endl;
  }

  return 0;
}


void generateCircle(int count, int range)
{
    
  int moddedCount = count - (count % 4);
  int radius = range - 2;
  int x = -1;

  int quads = count/4;

  cout << moddedCount << endl;
  
  Point ** pointSet = new Point*[moddedCount];
  
  for(int i = 0; i < quads; ++i)
  {
    double y = 0;
    do{
      ++x;
      y = circleYmaker(x%(radius+1), radius);
    } while(y - int(y) > 0.0);

    x = x%(radius+1);


    pointSet[4*i] = new Point(x, y);
    pointSet[4*i + 1] = new Point(x, -y);
    pointSet[4*i + 2] = new Point(-x, y);
    pointSet[4*i + 3] = new Point(-x, -y);

  }


  quickSortPointsX(pointSet, 0, moddedCount-1);
  tieBreakPoints(pointSet, moddedCount);

  for(int i = 0; i < moddedCount; ++i)
  {
    pointSet[i]->fileFormatDisplay();
  
  }
  
 }


double circleYmaker(int x, int radius)
{
  return sqrt(radius *  radius - x*x);
  
}

void quickSortPointsX(Point ** pArray, int lo, int hi)
{

  int i = lo;
  int j = hi;
  Point * temp;
  Point * pivot = pArray[(lo + hi)/2];

  while(i <= j)
  {
    while(pArray[i]->compareX(*pivot) == 1)
      i++;
    while(pArray[j]->compareX(*pivot) == -1)
      j--;
    if(i <= j)
    {
      temp = pArray[i];
      pArray[i] = pArray[j];
      pArray[j] = temp;
      i++;
      j--;
    }
  }

  if(lo < j)
    quickSortPointsX(pArray, lo, j);
  if(i < hi)
    quickSortPointsX(pArray, i, hi);

}


void quickSortPointsY(Point ** pArray, int lo, int hi)
{

  int i = lo;
  int j = hi;
  Point * temp;
  Point * pivot = pArray[(lo + hi)/2];

  while(i <= j)
  {
    while(pArray[i]->compareY(*pivot) == 1)
      i++;
    while(pArray[j]->compareY(*pivot) == -1)
      j--;
    if(i <= j)
    {
      temp = pArray[i];
      pArray[i] = pArray[j];
      pArray[j] = temp;
      i++;
      j--;
    }
  }

  if(lo < j)
    quickSortPointsY(pArray, lo, j);
  if(i < hi)
    quickSortPointsY(pArray, i, hi);

}

void tieBreakPoints(Point ** pArray, int size)
{
  for(int i = 0; i < size; ++i)
  {
    int j = 0;
    while(i+j+1 < size && pArray[i]->compareX(*pArray[i + j+1]) == 0)
      j++;

    if(j != 0)
      quickSortPointsY(pArray, i, i+j);
    }
}


void generateSorted(int count, int range)
{

  Point ** pointSet = new Point*[count];
  
  for(int i = 0; i < count; ++i)
  {
    int x = (rand()% (range *2 + 1)) - range;
    int y = (rand()% (range *2 + 1)) - range;
    pointSet[i] = new Point(x, y); 
  }

  quickSortPointsX(pointSet, 0, count-1);
  tieBreakPoints(pointSet, count);

  for(int i = 0; i < count; ++i)
  {
    pointSet[i]->fileFormatDisplay();
  
  }

}









