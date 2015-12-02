#include "line.h"
#include <iostream>
using namespace std;

//Prototypes.
line * calcLine(float p1[], float p2[]);
void bruteForce(int numPoints, float points[][3]);

int main() {
    int numPoints = 0;
    cin >> numPoints; cin.ignore();

    float points[numPoints][3];

    for (int i = 0; i < numPoints; ++i) {
        cin >> points[i][0]; cin.ignore();
        cin >> points[i][1]; cin.ignore();
        points[i][2] = 0;
    }

    //cout << "Set: ";
    //for (int i = 0; i < numPoints; ++i)
    //    cout << "[" << points[i][0] << ", " << points[i][1] << "]";
    //cout << endl;

    //Brute-force.
    bruteForce(numPoints, points);

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

    return 0;
}

line * calcLine(float p1[], float p2[]) {
    line *aLine = NULL;
    float numer = p1[0] - p2[0];
    if (numer == 0)
        aLine = new vertical(p1[0]);
    else {
        float denom = p1[1] - p2[1];
        if (denom == 0)
            aLine = new horizontal(p1[1]);
        else {
            aLine = new regLine(numer, denom, p1);
        }
    }
    return aLine;
}

void bruteForce(int numPoints, float points[][3]) { 
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
                        float next = aLine->whichSide(points[k]);
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


