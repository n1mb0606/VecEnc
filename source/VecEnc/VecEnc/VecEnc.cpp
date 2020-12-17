#include <iostream>
#include <vector>

using namespace std;
class Point {
private:
    int x;
    int y;

    int x_min;
    int y_min;

    int x_max;
    int y_max;

public:
    Point() {
        x = 0;
        y = 0;

        x_max = INT_MAX;
        y_max = INT_MAX;

        x_min = INT_MIN;
        y_min = INT_MIN;
    }
    Point(const int pos_x, const int pos_y) {
        x = pos_x;
        y = pos_y;

        x_max = INT_MAX;
        y_max = INT_MAX;

        x_min = INT_MIN;
        y_min = INT_MIN;
    }
    Point operator=(Point& Oper) {
        x = Oper.x;
        y = Oper.y;
        return *this;
    }
    Point operator+(Point& Oper) {
        const int ret_x = x + Oper.x;
        const int ret_y = y + Oper.y;
        return Point(ret_x, ret_y);

    }
    Point operator-(Point& Oper) {
        const int ret_x = x - Oper.x;
        const int ret_y = y - Oper.y;
        return Point(ret_x, ret_y);
    }
    void SetPos(const int pos_x, const int pos_y) {
        if ((pos_x >= x_min) && (pos_x <= x_max))   x = pos_x;
        if ((pos_y >= y_min) && (pos_y <= y_max))   y = pos_y;
    }
    void SetPosX(const int pos_x) {
        if ((pos_x >= x_min) && (pos_x <= x_max))   x = pos_x;
    }
    void SetPosY(const int pos_y) {
        if ((pos_y >= y_min) && (pos_y <= y_max))   y = pos_y;
    }
    void SetLimit(const int XMinVal, const int XMaxVal, const int YMinVal, const int YMaxVal) {
        x_max = XMaxVal;
        y_max = YMaxVal;

        x_min = XMinVal;
        y_min = YMinVal;
    }
    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }
    void PrtPos() {
        cout << "(" << GetX() << "," << GetY() << ")" << endl;
    }
};
int CharToInt(char c) {
    return ((c >= '0') && (c <= '9')) ? int(c - '0') : int(c - 'A' + 10);
}
char IntToChar(int i) {
    return ((i >= 0) && (i <= 9)) ? char(i + '0') : char(i + 'A' - 10);
}
int FindVec(Point& CurP, vector<vector<int>> map, int num, Point& VecP);
int FindVecNum(vector<Point> Map, Point Vec);
void VecSpl(Point VecP, Point& p1, Point& p2, int MapSize);
int main()
{
    //string DecDATA = "1A201FE";
    string DecDATA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<vector<int>> EncMap;
    vector<vector<int>> EncDATA;
    string EncStr;

    Point StPoint(2, 2);
    Point CursPoint(2,2);
    Point VecPoint;
    Point VecPoint1;
    Point VecPoint2;

    for (int i = 0; i < 6; i++) {
        vector<int> v;
        EncMap.push_back(v);
    }
    for (int i = 0; i < 6; i++) {
        vector<int> v;
        EncDATA.push_back(v);
    }
    EncMap = { {'A', '1', '2', '3', 'B','C' },
                {'4', '5', '6', '7','D','E'},
                {'8', '9', '0', 'F','G','H'},
                {'I', 'J', 'K', 'L','M','N' } ,
                {'O', 'P', 'R', 'S','T','U'} ,
                {'V', 'X', 'Y', 'Z','Q','W'} };

    EncDATA = { {'B', '1', '2', '3', 'A','C' },
                {'4', '5', '6', '7','D','E'},
                {'8', '9', '0', 'F','G','H'},
                {'I', 'J', 'K', 'L','M','N' } ,
                {'O', 'P', 'R', 'S','T','U'} ,
                {'V', 'X', 'Y', 'Z','Q','W'} };
    
    

    for (int i = 0; i < DecDATA.size(); i++) {
        if (FindVec(CursPoint, EncMap, DecDATA[i], VecPoint)) {
            VecSpl(VecPoint, VecPoint1, VecPoint2, EncDATA.size());
            EncStr.push_back(EncDATA[VecPoint1.GetX()][VecPoint1.GetY()]);
            EncStr.push_back(EncDATA[VecPoint2.GetX()][VecPoint2.GetY()]);
        }
    }
    for (int i = 0; i < EncStr.size(); i++) {
        cout << i<< "_" << EncStr[i] << endl;
    }

    return 0;
}
int FindVec(Point& CurP, vector<vector<int>> map, int num, Point& VecP) {
    int len = map.size();
    Point NumPos;
    bool ret = false;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (map[i][j] == num) {
                NumPos.SetPos(i, j);
                ret = true;
            }
        }
    }

    VecP.SetPos((NumPos - CurP).GetX(), (NumPos - CurP).GetY());
    CurP.SetPos(NumPos.GetX(), NumPos.GetY());
    return ret;
}
int FindVecNum(vector<Point> Map, Point Vec) {
    int ret = -1;
    for (int i = 0; i < Map.size(); i++) {
        if ((Map[i].GetX() == Vec.GetX()) && (Map[i].GetY() == Vec.GetY())) {
            ret = i;
            return ret;
        }
    }
    return ret;
}
void VecSpl(Point VecP, Point& p1, Point& p2, int MapSize) {
    Point OptP;
    Point MidP;

    int MinX = 0, MinY = 0;
    int MaxX = MapSize - 1, MaxY = MapSize - 1;
    int PlaneNum = 0;

    //make positive pos
    if (VecP.GetX() < 0) {
        OptP.SetPosX(VecP.GetX() + MapSize);
    }
    else {
        OptP.SetPosX(VecP.GetX());
    }
    if (VecP.GetY() < 0) {
        OptP.SetPosY(VecP.GetY() + MapSize);
    }
    else {
        OptP.SetPosY(VecP.GetY());
    }
    //plane for varity..
    //0 org plane, 1 right plane, 2 right down plane, 3 down plane
    
    PlaneNum = rand() % 4;
    if (OptP.GetX() == (MapSize - 1)) {
        if (OptP.GetY() == (MapSize - 1)) {
            PlaneNum = 0;
        }
        else {
            if (rand() % 2) {
                PlaneNum = 3;
            }
            else {
                PlaneNum = 0;
            }
        }
    }
    if (OptP.GetY() == (MapSize - 1)) {
        if (OptP.GetX() == (MapSize - 1)) {
            PlaneNum = 0;
        }
        else {
            if (rand() % 2) {
                PlaneNum = 1;
            }
            else {
                PlaneNum = 0;
            }
        }
    }
    switch (PlaneNum)
    {
    case 1:
        OptP.SetPosX(OptP.GetX() + MapSize);
        MinX = OptP.GetX() - MapSize + 1;
        MaxY = OptP.GetY();
        break;
    case 2:
        OptP.SetPosX(OptP.GetX() + MapSize);
        OptP.SetPosY(OptP.GetY() + MapSize);
        MinX = OptP.GetX() - MapSize + 1;
        MinY = OptP.GetY() - MapSize + 1;
        break;
    case 3:
        OptP.SetPosY(OptP.GetY() + MapSize);
        MinY = OptP.GetY() - MapSize + 1;
        MaxX = OptP.GetX();
        break;
    default:
        MaxX = OptP.GetX();
        MaxY = OptP.GetY();
        break;
    }

    
    if (MaxX == MinX) { MidP.SetPosX(MinX); }
    else {
        MidP.SetPosX(rand() % (MaxX - MinX) + MinX);
    }
    if (MaxY == MinY) { MidP.SetPosY(MinY); }
    else {
        MidP.SetPosY(rand() % (MaxY - MinY) + MinY);
    }
    

    p1 = MidP;
    p2.SetPos(OptP.GetX() - MidP.GetX(), OptP.GetY() - MidP.GetY());
}

/*
* 평문 -(평문 맵)> 벡터 -> 벡터 분할(2개) -> 복문
* ex E -> 1A
*/