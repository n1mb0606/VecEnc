#include "VecEnc.h"

VecEnc::VecEnc() {
	StP.SetPos(0, 0);
	CurP.SetPos(0, 0);

	StP.SetLimit(0, 0, 0, 0);
	CurP.SetLimit(0, 0, 0, 0);

	MapSize = 0;
}
int VecEnc::SetStPoint(const int x, const int y) {
	if ((x >= StP.GetXMinLimit()) && (x <= StP.GetXMaxLimit())) { StP.SetPosX(x); }
	else { return false; }
	if ((y >= StP.GetYMinLimit()) && (y <= StP.GetYMaxLimit())) { StP.SetPosY(y); }
	else { return false; }
	CurP.SetPos(StP.GetX(), StP.GetY());
	return true;
}
int VecEnc::SetStrToEnc(const std::string StrinToSet) {
	std::cout << "SETSTRTOENC" << std::endl;
	StrToEnc = StrinToSet;
	return StrToEnc.size();
}
int VecEnc::SetStrToDec(const std::string StrinToSet) {
	StrToDec = StrinToSet;
	return StrToDec.size();
}
int VecEnc::SetCharToVecMap(std::vector<std::vector<int>> VectorToSet) {
	for (std::vector<int> e1 : VectorToSet) {
		std::vector<int> v;
		for (int e2 : e1) {
			v.push_back(e2);
		}
		CharToVecMap.push_back(v);
	}
	MapSize = VectorToSet.size();
	StP.SetLimit(0, MapSize, 0, MapSize);
	CurP.SetLimit(-MapSize, MapSize, -MapSize, MapSize);
	return MapSize;
}
int VecEnc::SetVecToCharMap(std::vector<std::vector<int>> VectorToSet) {
	for (std::vector<int> e1 : VectorToSet) {
		std::vector<int> v;
		for (int e2 : e1) {
			v.push_back(e2);
		}
		VecToCharMap.push_back(v);
	}
	MapSize = VectorToSet.size();
	StP.SetLimit(0, MapSize, 0, MapSize);
	CurP.SetLimit(-MapSize, MapSize, -MapSize, MapSize);
	return MapSize;
}
std::string VecEnc::GetEncStr() {
	return EncStr;
}
std::string VecEnc::GetDecStr() {
	return DecStr;
}
int VecEnc::Encrypt() {
	if (IsCharToVecMapEmpty()) { return false; }
	if (IsVecToCharMapEmpty()) { return false; }
	
	EncStr.clear();
	for (int i = 0; i < StrToEnc.size(); i++) {
		if (FindVec(CurP, CharToVecMap, StrToEnc[i], Vec)) {
			RandPntGen(RandVec, Vec, CharToVecMap.size());
			SplitVector(Vec1, Vec2, RandVec, Vec);
			EncStr.push_back(VecToCharMap[Vec1.GetX()][Vec1.GetY()]);
			EncStr.push_back(VecToCharMap[Vec2.GetX()][Vec2.GetY()]);
			//PrtStat();
		}
	}
	EndP.SetPos(CurP.GetX(), CurP.GetY());
	InitCurP();
	return true;
}
int VecEnc::Decrypt() {
	InitCurP();
	if (IsCharToVecMapEmpty()) { return false; }
	if (IsVecToCharMapEmpty()) { return false; }

	DecStr.clear();
	for (int i = 0; i < StrToDec.size(); i += 2) {
        CharToVec(StrToDec[i], VecToCharMap, Vec1);
        CharToVec(StrToDec[size_t(i) + 1], VecToCharMap, Vec2);
        DecStr.push_back(FindChar(CurP, CharToVecMap, Vec1, Vec2));
		//PrtStat();
	}

	EndP.SetPos(CurP.GetX(), CurP.GetY());
	
	return true;
}
int VecEnc::IsCharToVecMapEmpty() {
	return CharToVecMap.empty();
}
int VecEnc::IsVecToCharMapEmpty() {
	return VecToCharMap.empty();
}
void VecEnc::InitCurP() {
	CurP.SetPos(StP.GetX(), StP.GetY());
}
//FOR DBG
void VecEnc::PrtStP() {
	std::cout << "StP (" << StP.GetX() << " ," << StP.GetY() << ")" << std::endl;
}
void VecEnc::PrtEndP() {
	std::cout << "EndP (" << EndP.GetX() << " ," << EndP.GetY() << ")" << std::endl;
}
void VecEnc::PrtCurP() {
	std::cout << "CurP (" << CurP.GetX() << " ," << CurP.GetY() << ")" << std::endl;
}
void VecEnc::PrtStat() {
	std::cout << "StP (" << StP.GetX() << " ," << StP.GetY() << ")" << std::endl;
	std::cout << "CurP (" << CurP.GetX() << " ," << CurP.GetY() << ")" << std::endl;
	std::cout << "EndP (" << EndP.GetX() << " ," << EndP.GetY() << ")" << std::endl;
	std::cout << "MapSize : " << MapSize << std::endl;
	std::cout << "Ischartovecmapempty : " << CharToVecMap.empty() << std::endl;
	std::cout << "Isvectocharmapempty : " << VecToCharMap.empty() << std::endl;
	std::cout << "Vec (" << Vec.GetX() << " ," << Vec.GetY() << ")" << std::endl;
}