#include "FunctionalDependency.h"

FunctionalDependency::FunctionalDependency(string aArrowB) {
	string pA;
	string pB;

	ParseArrow(aArrowB, pA, pB);
	mA = new Set(pA);
	mB = new Set(pB);
}

FunctionalDependency::~FunctionalDependency(){
	delete mA;
	delete mB;
}

void FunctionalDependency::ParseArrow(string aArrowB, string& pA, string& pB) {
	sting pInString;
	istringstream in(aArrowB);

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