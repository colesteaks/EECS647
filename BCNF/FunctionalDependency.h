#pragma once
#include <sstream>
#include <string>
#include <vector>
#include "Set.h"
using namespace std;
class FunctionalDependency{
public:
	FunctionalDependency(string aArrowB);
	~FunctionalDependency();
	Set* GetA();
	Set* GetB();
	bool IsEqual(FunctionalDependency* fd);
private:
	Set* mA;
	Set* mB;
	void ParseArrow(string aArrowB, string& pA, string& pB);
};

typedef vector<FunctionalDependency*> FDSet;