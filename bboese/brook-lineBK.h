//Convexhull Project cs350 Fall 2015

//include a calcLine function that identified the line and returns a line.

//Base class.
class line {
    public:
        line();
        ~line();
        virtual int whichSide(const float * point) = 0;
        virtual float distance(const float * point) = 0;
};

class regLine: public line {
    public:
        regLine();
        regLine(float numer, float denom, const float point[2]);
        ~regLine();
        int whichSide(const float point[2]);
        float distance(const float point[2]);
    private:
        float slope;
        float constant;
};

class vertical: public line {
    public:
        vertical();
        vertical(float xValue);
        ~vertical();
        int whichSide(const float point[2]);
        float distance(const float point[2]);
    private:
        float x;
};

class horizontal: public line {
    public:
        horizontal();
        horizontal(float yValue);
        ~horizontal();
        int whichSide(const float point[2]);
        float distance(const float point[2]);
    private:
        float y;
};





