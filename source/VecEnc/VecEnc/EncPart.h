#pragma once
#include <vector>

#include "Point.h"

int FindVec(Point& CurP, std::vector<std::vector<int>> map, int num, Point& VecP);
int RandPntGen(Point& RandPoint, Point& EndPoint, int MapSize);
void SplitVector(Point& FirstVec, Point& SecondVec, Point SplPoint, Point EndPoint);