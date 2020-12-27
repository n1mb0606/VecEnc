#pragma once

#include <vector>

#include "Point.h"

int CharToVec(char encVec, std::vector<std::vector<int>> map, Point& DecVec);
char FindChar(Point& CurP, std::vector<std::vector<int>> map, Point Vec1, Point Vec2);