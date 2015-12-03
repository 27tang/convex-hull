//Convexhull Proect cs350 Fall 2015
#include "brook-line.h"

//Base class.
line::line() {}

line::~line() {}


//Non-vertical, non-horizontal line.
regLine::regLine() {
    this->slope = 0;
    this->constant = 0;
}

regLine::regLine(float numer, float denom, const float point[2]) {
    slope = numer/denom;
    this->constant = point[1] - this->slope * point[0];
}

regLine::~regLine() {
    this->slope = 0;
    this->constant = 0;
}

int regLine::whichSide(const float point[2]) {
    float y = this->slope * point[0] + this->constant;
    if (point[1] < y)
        return -1;
    if (point[1] == y)
        return 0;
    return 1;
}


float regLine::distance(const float point[2]) {
    float y = this->slope * point[0] + this->constant;
    y = point[1] - y;
    if (y < 0)
        y = y * -1;
    return y;
}

//Vertical line.
vertical::vertical() {
    this->x = 0;
}

vertical::vertical(float xValue) {
    this->x = xValue;
}

vertical::~vertical() {
    this->x = 0;
}

int vertical::whichSide(const float point[2]) {
    if (point[0] < this->x)
        return -1;
    if (point[0] == this->x)
        return 0;
    return 1;
}

float vertical::distance(const float point[2]) {
    float d = point[0] - this->x;
    if (d < 0)
        d = d * -1;
    return d;
}


//Horizontal line.
horizontal::horizontal() {
    this->y = 0;
}

horizontal::horizontal(float yValue) {
    this->y = yValue;
}

horizontal::~horizontal() {
    this->y = 0;
}

int horizontal::whichSide(const float point[2]) {
    if (point[1] < this->y)
        return -1;
    if (point[1] == y)
        return 0;
    return 1;
}

float horizontal::distance(const float point[2]) {
    float d = point[1] - this->y;
    if (d < 0)
        d = d * -1;
    return d;
}






