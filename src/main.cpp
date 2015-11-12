#include <iostream>
#include "convex_hull.h"
using namespace std;

int main()
{
  
  cout << endl << "Hello Everybuddy" << endl;
  cout << endl;

  //testing Point class
  cout << "creating a point with coordinates (4,10)..." <<endl;
  cout << "Displaying:  " << endl;
  Point * testPoint = new Point(4,10);
  testPoint->display();
  cout << endl;
  return 0;
}
