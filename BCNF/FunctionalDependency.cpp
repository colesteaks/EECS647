#include "FunctionalDependency.h"
using namespace std;

FunctionalDependency::FunctionalDependency(std::string aArrowB) {
	std::string pA;
	std::string pB;

	ParseArrow(aArrowB, pA, pB);
	mA = new Set(pA);
	mB = new Set(pB);
}

FunctionalDependency::~FunctionalDependency(){
	delete mA;
	delete mB;
}

void FunctionalDependency::ParseArrow(std::string aArrowB, std::string& pA, std::string& pB) {
	std::string pInString;
	std::istringstream in(aArrowB);

	bool pInA = true;
	while (in >> pInString){
		if(pInString == "-->"){
			pInA = false;
		} else if (pInA) {
			pA = pA + " " + pInString;
		} else {
			pB = pB + " " + pInString;
		}
	}
}

Set* FunctionalDependency::GetA() {return mA;}
Set* FunctionalDependency::GetB() {return mB;}
bool FunctionalDependency::IsEqual(FunctionalDependency* fd) {
	return (!mA->IsEqual(fd->GetA()) && !mB->IsEqual(fd->GetB()));
}