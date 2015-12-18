#include "FunctionalDependency.h"
using namespace std;

//constructor declaring the structure of a functional dependency.
//each FD has a A->B structure, where the both the A and B sides could be represented by
//multiple values
FunctionalDependency::FunctionalDependency(std::string aArrowB) {
	std::string pA;
	std::string pB;

	ParseArrow(aArrowB, pA, pB);
	mA = new Set(pA);
	mB = new Set(pB);
}

//deconstructor for functinal dependencies
FunctionalDependency::~FunctionalDependency(){
	delete mA;
	delete mB;
}

//this function parses the passed in functional dependencies (which are in the form of a string)
//assigns the values on the left of the arrow in the string as part of the left side and the values
//on the right of the string as part of the right side.
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

//functions to return the set of variables on the left and right side of the
//arrow in a functional dependency.
Set* FunctionalDependency::GetA() {return mA;}
Set* FunctionalDependency::GetB() {return mB;}

//compares functional dependencies for equality.
bool FunctionalDependency::IsEqual(FunctionalDependency* fd) {
	return (!mA->IsEqual(fd->GetA()) && !mB->IsEqual(fd->GetB()));
}
