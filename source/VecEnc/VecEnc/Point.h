#pragma once
#include <iostream>

class Point {
private:
    int x;
    int y;

    int x_min;
    int y_min;

    int x_max;
    int y_max;

public:
    Point();
    Point(const int pos_x, const int pos_y);

    Point operator=(Point& Oper);
    Point operator+(Point& Oper);
    Point operator-(Point& Oper);

    void SetPos(const int pos_x, const int pos_y);
    void SetPosX(const int pos_x);
    void SetPosY(const int pos_y);
    void SetLimit(const int XMinVal, const int XMaxVal, const int YMinVal, const int YMaxVal);

    int GetX();
    int GetY();
    
    int GetXMinLimit();
    int GetXMaxLimit();
    int GetYMinLimit();
    int GetYMaxLimit();

    void PrtPos();
};
