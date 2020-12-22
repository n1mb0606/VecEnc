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
int FindVec(Point& CurP, vector<vector<int>> map, int num, Point& VecP);
void RandVecSpl(Point VecP, Point& p1, Point& p2, int MapSize);
char FindChar(Point& CurP, vector<vector<int>> map, Point Vec1, Point Vec2);
int CharToVec(char encVec, vector<vector<int>> map, Point& DecVec);
int RandPntGen(Point& RandPoint, Point& EndPoint, int MapSize);
void SplitVector(Point& FirstVec, Point& SecondVec, Point SplPoint, Point EndPoint);
int main()
{
    //string DecDATA = "1A201FE";
    string DecStr = "HELLOWORLD1357";
    vector<vector<int>> EncMap;
    vector<vector<int>> EncDATA;
    string EncStr;

    Point StPoint(2, 2);
    Point CursPoint(2,2);
    Point VecPoint;
    Point VecPoint1;
    Point VecPoint2;
    Point RandPoint;

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
    
    

    for (int i = 0; i < DecStr.size(); i++) {
        if (FindVec(CursPoint, EncMap, DecStr[i], VecPoint)) {
            RandPntGen(RandPoint, VecPoint, EncMap.size());
            SplitVector(VecPoint1, VecPoint2, RandPoint, VecPoint);
            EncStr.push_back(EncDATA[VecPoint1.GetX()][VecPoint1.GetY()]);
            EncStr.push_back(EncDATA[VecPoint2.GetX()][VecPoint2.GetY()]);
        }
    }
    for (int i = 0; i < EncStr.size(); i++) {
        cout << i<< "_" << EncStr[i] << endl;
    }

   
    Point DecCPoint;
    DecCPoint.SetPos(StPoint.GetX(), StPoint.GetY());

    string DecString;
    Point DecV1, DecV2;
    char DecChar;
    for (int i = 0; i < EncStr.size(); i += 2) {
        CharToVec(EncStr[i], EncDATA, DecV1);
        CharToVec(EncStr[size_t(i) + 1], EncDATA, DecV2);
        //cout << "vec1" << DecV1.GetX() << "," << DecV1.GetY() << endl;
        //cout << "vec2" << DecV2.GetX() << "," << DecV2.GetY() << endl;
        DecString.push_back(FindChar(DecCPoint, EncMap, DecV1, DecV2));
    }

    for (char e : DecString) {
        cout << e;
    }
    cout << endl;
    return 0;
}
int FindVec(Point& CurP, vector<vector<int>> map, int num, Point& VecP) {
    int len = map.size();
    Point NumPos;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (map[i][j] == num) {
                NumPos.SetPos(i, j);

                VecP.SetPos((NumPos - CurP).GetX(), (NumPos - CurP).GetY());
                CurP.SetPos(NumPos.GetX(), NumPos.GetY());
                return true;
            }
        }
    }    
    return false;
}
void RandVecSpl(Point VecP, Point& p1, Point& p2, int MapSize) {
    /*
    void VecSpl(Point VecP, Point& p1, Point& p2, int MapSize)
    - Description
    Split a vector.
    ex) Point(4,5) to Point(2, 3) and Point(2, 2) or
                      Point(1, 3) and Point(3, 2) etc.
    - Parameters
    Point VecP : Vector to Devide.
    Point& p1 : First Devided Vector from VecP.
    Point& p2 : Second Devided Vecotr from VecP.
    int MapSize : Map size to make minimum and maximum point
    - Return
    void

    - Variables
    Point OptP : Optimized Point. Make negative Point(ex. Point(-1, -1)) to positive Point(1,1)
    Point MidP : Mid Point. Random Point between origin point to Optimized point.

    int MinX, MinY, MaxX, MaxY : Minimum and maximum values to limit random values.

    int PlaneNum : Make vary Optimized Point.
    */
    Point OptP;
    Point MidP;

    int MinX = 0, MinY = 0;
    int MaxX = MapSize - 1, MaxY = MapSize - 1;
    int PlaneNum = 0;

    //Make Negative Point to Positive Point.
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

    //Make limits to make random Point(MidP).
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

    //Check Divided by zero, Make a random Point(MidP).
    if (MaxX == MinX) { MidP.SetPosX(MinX); }
    else {
        MidP.SetPosX(rand() % (MaxX - MinX) + MinX);
    }
    if (MaxY == MinY) { MidP.SetPosY(MinY); }
    else {
        MidP.SetPosY(rand() % (MaxY - MinY) + MinY);
    }
    
    //Assign Divided Points.
    p1 = MidP;
    p2.SetPos(OptP.GetX() - MidP.GetX(), OptP.GetY() - MidP.GetY());
}
int RandPntGen(Point& RandPoint, Point& EndPoint, int MapSize) {
    Point OptP;
    Point MidP;

    int MinX = 0, MinY = 0;
    int MaxX = MapSize - 1, MaxY = MapSize - 1;
    int PlaneNum = 0;

    //Make Negative Point to Positive Point.
    if (EndPoint.GetX() < 0) {
        OptP.SetPosX(EndPoint.GetX() + MapSize);
    }
    else {
        OptP.SetPosX(EndPoint.GetX());
    }
    if (EndPoint.GetY() < 0) {
        OptP.SetPosY(EndPoint.GetY() + MapSize);
    }
    else {
        OptP.SetPosY(EndPoint.GetY());
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

    //Make limits to make random Point(MidP).
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

    //Check Divided by zero, Make a random Point(MidP).
    if (MaxX == MinX) { MidP.SetPosX(MinX); }
    else {
        MidP.SetPosX(rand() % (MaxX - MinX) + MinX);
    }
    if (MaxY == MinY) { MidP.SetPosY(MinY); }
    else {
        MidP.SetPosY(rand() % (MaxY - MinY) + MinY);
    }

    RandPoint.SetPos(MidP.GetX(), MidP.GetY());
    EndPoint.SetPos(OptP.GetX(), OptP.GetY());
    return true;
}
void SplitVector(Point& FirstVec, Point& SecondVec, Point SplPoint, Point EndPoint) {
    FirstVec = SplPoint;
    SecondVec.SetPos(EndPoint.GetX() - SplPoint.GetX(), EndPoint.GetY() - SplPoint.GetY());
}
int CharToVec(char encVec, vector<vector<int>> map, Point& DecVec) {
    int len = map.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (map[i][j] == encVec) {
                DecVec.SetPosX(i);
                DecVec.SetPosY(j);
                return true;
            }
        }
    }
    return false;
}
char FindChar(Point& CurP, vector<vector<int>> map, Point Vec1, Point Vec2) {
    int len = map.size();
    Point OptP;
    OptP.SetPosX((CurP.GetX() + Vec1.GetX() + Vec2.GetX()) % len);
    OptP.SetPosY((CurP.GetY() + Vec1.GetY() + Vec2.GetY()) % len);
    cout << "optp" << OptP.GetX() << "," << OptP.GetY() << endl;

    CurP.SetPos(OptP.GetX(), OptP.GetY());
    return  map[OptP.GetX()][OptP.GetY()];    
}