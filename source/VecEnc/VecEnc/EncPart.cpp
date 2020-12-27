#include "EncPart.h"

int FindVec(Point& CurP, std::vector<std::vector<int>> map, int num, Point& VecP) {
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
int RandPntGen(Point& RandPoint, Point& EndPoint, int MapSize) {
    /*
    int RandPntGen(Point& RandPoint, Point& EndPoint, int MapSize)
    - Description
    Make a random point to split vectors.

    - Parameters
    Point RandPoint : Random point(return).
    Point& EndPoint : End point(return).
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

    srand(time(NULL));
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