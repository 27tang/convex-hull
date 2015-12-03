#include "brook-line.h"
#include <iostream>
#include <ctime>
using namespace std;

//Prototypes.
line * calcLine(float p1[], float p2[]);
void quickHull(int numPoints, float points[][3]);
void qhAbove(int numPoints, float **points);
void qhBelow(int numPoints, float **points);

int main() {
    int numPoints = 0;
    cin >> numPoints; cin.ignore();

    float points[numPoints][3];

    for (int i = 0; i < numPoints; ++i) {
        cin >> points[i][0]; cin.ignore();
        cin >> points[i][1]; cin.ignore();
        points[i][2] = 0;
    }

//    cout << numPoints << "\n";
//    for (int i = 0; i < numPoints; ++i)
//        cout << points[i][0] << "\n" << points[i][1] << "\n";


    clock_t t = clock();

    //Quickhull.  
    quickHull(numPoints, points);

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

line * calcLine(float p1[], float p2[]) {
    line *aLine = NULL;
    float numer = p1[1] - p2[1];
    if (numer == 0)
        aLine = new horizontal(p1[1]);
    else {
        float denom = p1[0] - p2[0];
        if (denom == 0)
            aLine = new vertical(p1[0]);
        else {
            aLine = new regLine(numer, denom, p1);
        }
    }
    return aLine;
}

void quickHull(int numPoints, float points[][3]) {
    if (numPoints < 4) {
        for (int i = 0; i < numPoints; ++i)
            points[i][2] = 1;
        return;
    }

    float *leftMost = points[0];
    float *rightMost = points[numPoints - 1];
    line *middleLine = calcLine(leftMost, rightMost);
    leftMost[2] = 1;
    rightMost[2] = 1;
    
    float *upperLeft[numPoints];
    int upperCount = 1;
    
    float *lowerLeft[numPoints];
    int lowerCount = 1;

    int maxYIndex = 0;
    int minYIndex = 0;
    float maxYDist = 0;
    float minYDist = 0;

    upperLeft[0] = points[0];
    lowerLeft[0] = points[0];

    for (int i = 1; i < numPoints - 1; ++i) {
        int side = middleLine->whichSide(points[i]);

        if (side > 0) {
            upperLeft[upperCount] = points[i];
         
            float nextDist = middleLine->distance(points[i]);
            if (maxYDist < nextDist) {
                maxYDist = nextDist;
                maxYIndex = upperCount;
            }

            ++upperCount;
        }

        else if (side < 0) {
            lowerLeft[lowerCount] = points[i];

            float nextDist = middleLine->distance(points[i]);
            if (minYDist < nextDist) {
                minYDist = nextDist;
                minYIndex = lowerCount;
            }

            ++lowerCount;
        }
    }

    upperLeft[upperCount] = rightMost;
    ++upperCount;
    lowerLeft[lowerCount] = rightMost;
    ++lowerCount;

    upperLeft[maxYIndex][2] = 1;
    lowerLeft[minYIndex][2] = 1;
    
    //If there are points above the line aside from the max point.
    if (upperCount > 3) {
        int ulCount = maxYIndex + 1;
        int urCount = upperCount - maxYIndex;
        
        //If there need to be an upper-right.
        if (urCount > 2) {
            float *upperRight[urCount];

            upperRight[0] = upperLeft[maxYIndex];

            for (int ur = 1, ul = maxYIndex + 1; ul < upperCount; ++ur, ++ul) {
                upperRight[ur] = upperLeft[ul];
                upperLeft[ul] = NULL;
            }
            //call upper-right recursive function.
            qhAbove(urCount, upperRight);
        }
        //If there are only points above the line between points[maxYIndex] and
        //points[numPoints -1] (points in above the line to the left of the max point).
        if (ulCount > 2) {
            //call upper-left recursive function.
            qhAbove(ulCount, upperLeft);
        }
    }

    if (lowerCount > 3) {
        int llCount = minYIndex + 1;
        int lrCount = lowerCount - minYIndex;

        //If there need to be an upper-right.
        if (lrCount > 2) {
            float *lowerRight[lrCount];

            lowerRight[0] = lowerLeft[minYIndex];

            for (int lr = 1, ll = minYIndex + 1; ll < lowerCount; ++lr, ++ll) {
                lowerRight[lr] = lowerLeft[ll];
                lowerLeft[ll] = NULL;
            }
            //call lower-right recursive function.
            qhBelow(lrCount, lowerRight);

        }
        //If there are only points above the line between points[minYIndex] and
        //points[numPoints -1] (points in below the line to the left of the min point).
        if (llCount > 2) {
                qhBelow(llCount, lowerLeft);
        }
    }
}

void qhAbove(int numPoints, float **points) {
    float *upperLeft[numPoints];
    line *aLine = calcLine(points[0], points[numPoints - 1]);
    int furthestI = 0;
    float dist = 0;
    int count = 1;

    upperLeft[0] = points[0];

    for (int i = 1; i < numPoints - 1; ++i) {
        int side = aLine->whichSide(points[i]);

        if (side > 0) {
            upperLeft[count] = points[i]; 

            float nextDist = aLine->distance(points[i]);
            if (dist < nextDist) {
                dist = nextDist;
                furthestI = count;
            }
            ++count;
        }
    }
    upperLeft[count] = points[numPoints - 1];
    ++count;

    upperLeft[furthestI][2] = 1;

    if (count > 3) {
        int ulCount = furthestI + 1;
        int urCount = count - furthestI;

        if (urCount > 2) {
            float *upperRight[urCount];

            upperRight[0] = upperLeft[furthestI];

            for (int ur = 1, ul = furthestI + 1; ul < count; ++ur, ++ul) {
                upperRight[ur] = upperLeft[ul];
                upperLeft[ul] = NULL;
            }
            qhAbove(urCount, upperRight);

        }
        if (ulCount > 2) {
            qhAbove(ulCount, upperLeft);
        }  
    }
}

void qhBelow(int numPoints, float **points) {
    float *lowerLeft[numPoints];
    line *aLine = calcLine(points[0], points[numPoints - 1]);
    int furthestI = 0;
    float dist = 0;
    int count = 1;

    lowerLeft[0] = points[0];

    for (int i = 1; i < numPoints - 1; ++i) {
        int side = aLine->whichSide(points[i]);

        if (side < 0) {
            lowerLeft[count] = points[i]; 

            float nextDist = aLine->distance(points[i]);
            if (dist < nextDist) {
                dist = nextDist;
                furthestI = count;
            }
            ++count;
        }
    }

    lowerLeft[count] = points[numPoints - 1];
    ++count;

    lowerLeft[furthestI][2] = 1;

    if (count > 3) {
        int llCount = furthestI + 1;
        int lrCount = count - furthestI;
        
        if (lrCount > 2) {
            float *lowerRight[lrCount];

            lowerRight[0] = lowerLeft[furthestI];

            for (int lr = 1, ll = furthestI + 1; ll < count; ++lr, ++ll) {
                lowerRight[lr] = lowerLeft[ll];
                lowerLeft[ll] = NULL;
            }
            qhBelow(lrCount, lowerRight);
        }
        if (llCount > 2) {
            qhBelow(llCount, lowerLeft);
        }
    }
}

