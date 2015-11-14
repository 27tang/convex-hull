#include <iostream>
#include "point-line.h"
using namespace std;

int main()
{
  
  cout << endl << "Hello Everybuddy" << endl;
  cout << endl;

  //testing Point class
  cout << "creating a point with coordinates (4,10)..." <<endl;
  cout << "Displaying:  " << endl;
  Point testPoint(4, 10);
  testPoint.display();
  cout << endl;

  cout << "testing Verticalline creation..." << endl;
  Point p1(10, 20);
  Point p2(10, 30);
  Line * testLine1 = new VerticalLine(p1, p2);
  testLine1->display();
  cout << endl;

  cout << "testing HorizLine creation..." << endl;
  Point p3(20, 4);
  Point p4(12, 4);
  Line * testLine2 = new HorizontalLine(p3,p4);
  testLine2->display();
  cout << endl;


  cout << "testing SkewLine creation..." << endl;
  Point p5(2, 4);
  Point p6(4, 6);
  Line * testLine3 = new SkewLine(p5, p6);
  testLine3->display();
  cout << endl;

  cout << "testing WhichSideOfLine for Vertical" << endl;
  cout << "testpoint is: "; testPoint.display(); cout << endl;
  int result = testLine1->whichSideOfLine(testPoint);
  cout << "RESULT: " << result << endl;

  cout << "testing WhichSideOfLine for Horizontal" << endl;
  cout << "testpoint is: "; testPoint.display(); cout << endl;
  result = testLine2->whichSideOfLine(testPoint);
  cout << "RESULT: " << result << endl;

  cout << "testing WhichSideOfLine for Skew" << endl;
  cout << "testpoint is: "; testPoint.display(); cout << endl;
  result = testLine3->whichSideOfLine(testPoint);
  cout << "RESULT: " << result << endl;

  Point testPoint2(6, 8);
  cout << "testing WhichSideOfLine for Skew" << endl;
  cout << "testpoint is: "; testPoint2.display(); cout << endl;
  result = testLine3->whichSideOfLine(testPoint2);
  cout << "RESULT: " << result << endl;


  cout << "USER INPUT TEST whichSideOfLine for skew (-1000 to quit)" << endl;
  while(1)
  {
    int x; int y;
    cout << "enter x coor for test point: " << endl;
    cin >> x; cin.ignore();
    if(x == -1000)
      break;
    cout << "enter y coor for test point: " << endl;
    cin >> y; cin.ignore();

    Point tp(x, y);
    cout << "testpoint is: "; tp.display(); cout << endl;
    result = testLine3->whichSideOfLine(tp);
    cout << "RESULT: " << result << endl;

 
  
  }


  return 0;
}
