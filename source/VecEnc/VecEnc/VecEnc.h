#pragma once
#include <iostream>
#include <vector>

#include "EncPart.h"
#include "DecPart.h"
#include "Point.h"

class VecEnc
{
	std::string StrToEnc;
	std::string StrToDec;

	std::string EncStr;
	std::string DecStr;

	Point CurP;
	Point StP;
	Point EndP;
	
	int MapSize;
	std::vector<std::vector<int>> CharToVecMap;
	std::vector<std::vector<int>> VecToCharMap;

	Point Vec;
	Point Vec1;
	Point Vec2;
	Point RandVec;
	
public:
	VecEnc();
	int SetStPoint(int, int);
	int SetStrToEnc(std::string);
	int SetStrToDec(std::string);
	
	int SetCharToVecMap(std::vector<std::vector<int>>);
	int SetVecToCharMap(std::vector<std::vector<int>>);

	std::string GetEncStr();
	std::string GetDecStr();

	int Encrypt();
	int Decrypt();

	int IsCharToVecMapEmpty();
	int IsVecToCharMapEmpty();

	void PrtStat();
	void PrtStP();
	void PrtEndP();
	void PrtCurP();
private:
	void InitCurP();
};