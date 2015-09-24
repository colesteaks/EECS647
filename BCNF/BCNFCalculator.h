#pragma once
#include <bitset>
#include <iostream>
#include "Set.h"
#include "FunctionalDependency.h"
using namespace std;
class BCNFCalculator {
public:
	BCNFCalculator() {};
	~BCNFCalculator() {};
	vector<Set*> BCNF(Set* R, FDSet S);
	Set* Closure(Set* Q, FDSet S);
private:
	bool IsKey(Set* possibleKey, Set* relation);
	void Split(Set* R, Set*& R1, Set*& R2, FDSet S, FDSet& S1, FDSet& S2, Set* problemAs);
	void SplitFDs(Set* R, Set* R1, FDSet S, FDSet& S1);
	vector<Set*> GetAllSubsets(Set* S);
};