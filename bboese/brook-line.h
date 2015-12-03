//Convexhull Project cs350 Fall 2015

//include a calcLine function that identified the line and returns a line.

//Base class.
class line {
    public:
        line();
        ~line();
        virtual int whichSide(const int * point) = 0;
        virtual float distance(const int * point) = 0;
};

class regLine: public line {
    public:
        regLine();
        regLine(int numer, int denom, const int point[2]);
        ~regLine();
        int whichSide(const int point[2]);
        float distance(const int point[2]);
    private:
        float slope;
        float constant;
};

class vertical: public line {
    public:
        vertical();
        vertical(int xValue);
        ~vertical();
        int whichSide(const int point[2]);
        float distance(const int point[2]);
    private:
        int x;
};

class horizontal: public line {
    public:
        horizontal();
        horizontal(int yValue);
        ~horizontal();
        int whichSide(const int point[2]);
        float distance(const int point[2]);
    private:
        int y;
};





