#include "brook-line.h"
#include <iostream>
#include <ctime>
using namespace std;

//Prototypes.
line * calcLine(int p1[], int p2[]);
void bruteForce(int numPoints, int points[][3]);

int main() {
    int numPoints = 0;
    cin >> numPoints; cin.ignore();

    int points[numPoints][3];

    for (int i = 0; i < numPoints; ++i) {
        cin >> points[i][0]; cin.ignore();
        cin >> points[i][1]; cin.ignore();
        points[i][2] = 0;
    }

//DISPLAY
/* 
    cout << numPoints << "\n";
    for (int i = 0; i < numPoints; ++i)
        cout << points[i][0] << "\n" << points[i][1] << "\n";
*/
    clock_t t = clock();

    //Brute-force.
    bruteForce(numPoints, points);

    t = clock() - t;  
    cout << t << endl;

/*    
    int total = 0;
    for (int i = 0; i < numPoints; ++i) {
        if (points[i][2] == 1){
            ++total;
        }
    }
    
    cout << total << "\n";

    for (int i = 0; i < numPoints; ++i) {
        if (points[i][2] == 1) {
            cout << points[i][0] << "\n"
                 << points[i][1] << "\n";
        }
    }
*/
    return 0;
}

line * calcLine(int p1[], int p2[]) {
    line *aLine = NULL;
    int numer = p1[1] - p2[1];
    if (numer == 0)
        aLine = new horizontal(p1[1]);
    else {
        int denom = p1[0] - p2[0];
        if (denom == 0)
            aLine = new vertical(p1[0]);
        else {
            aLine = new regLine(numer, denom, p1);
        }
    }
    return aLine;
}

void bruteForce(int numPoints, int points[][3]) { 
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            line *aLine = calcLine(points[i], points[j]);
            
            int first = 0;
            int k = 0;
            bool SFSGood = true;
            while (k <numPoints && SFSGood == true) {
                if (k != i && k != j) {
                    if (first == 0)
                        first = aLine->whichSide(points[k]);
                    else {
                        int next = aLine->whichSide(points[k]);
                        if (next != 0 && first != next)
                            SFSGood = false;
                    }
                }
                ++k;
            }
            if (SFSGood == true) {
                points[i][2] = 1;
                points[j][2] = 1;
            }
        }
    }
}


