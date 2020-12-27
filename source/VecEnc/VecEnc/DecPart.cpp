#include "DecPart.h"

int CharToVec(char encVec, std::vector<std::vector<int>> map, Point& DecVec) {
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
char FindChar(Point& CurP, std::vector<std::vector<int>> map, Point Vec1, Point Vec2) {
    int len = map.size();
    Point OptP;
    OptP.SetPosX((CurP.GetX() + Vec1.GetX() + Vec2.GetX()) % len);
    OptP.SetPosY((CurP.GetY() + Vec1.GetY() + Vec2.GetY()) % len);

    CurP.SetPos(OptP.GetX(), OptP.GetY());
    return  map[OptP.GetX()][OptP.GetY()];
}