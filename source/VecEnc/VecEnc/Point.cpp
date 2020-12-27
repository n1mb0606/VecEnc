#include "Point.h"
Point::Point() {
    x = 0;
    y = 0;

    x_max = INT_MAX;
    y_max = INT_MAX;

    x_min = INT_MIN;
    y_min = INT_MIN;
}
Point::Point(const int pos_x, const int pos_y) {
    x = pos_x;
    y = pos_y;

    x_max = INT_MAX;
    y_max = INT_MAX;

    x_min = INT_MIN;
    y_min = INT_MIN;
}
Point Point::operator=(Point& Oper) {
    x = Oper.x;
    y = Oper.y;
    return *this;
}
Point Point::operator+(Point& Oper) {
    const int ret_x = x + Oper.x;
    const int ret_y = y + Oper.y;
    return Point(ret_x, ret_y);

}
Point Point::operator-(Point& Oper) {
    const int ret_x = x - Oper.x;
    const int ret_y = y - Oper.y;
    return Point(ret_x, ret_y);
}
void Point::SetPos(const int pos_x, const int pos_y) {
    if ((pos_x >= x_min) && (pos_x <= x_max))   x = pos_x;
    if ((pos_y >= y_min) && (pos_y <= y_max))   y = pos_y;
}
void Point::SetPosX(const int pos_x) {
    if ((pos_x >= x_min) && (pos_x <= x_max))   x = pos_x;
}
void Point::SetPosY(const int pos_y) {
    if ((pos_y >= y_min) && (pos_y <= y_max))   y = pos_y;
}
void Point::SetLimit(const int XMinVal, const int XMaxVal, const int YMinVal, const int YMaxVal) {
    x_max = XMaxVal;
    y_max = YMaxVal;

    x_min = XMinVal;
    y_min = YMinVal;
}
int Point::GetX() {
    return x;
}
int Point::GetY() {
    return y;
}
int Point::GetXMinLimit() {
    return x_min;
}
int Point::GetXMaxLimit() {
    return x_max;
}
int Point::GetYMinLimit() {
    return y_min;
}
int Point::GetYMaxLimit() {
    return y_max;
}
void Point::PrtPos() {
    std::cout << "(" << GetX() << "," << GetY() << ")" << std::endl;
}