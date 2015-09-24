#include "BCNFCalculator.h"
using namespace std;

std::vector<Set*> BCNFCalculator::BCNF(Set* R, FDSet S) {
	if(S.size() > 0){
		for (size_t i = 0; i < S.size(); i++) {
			Set* pAs = S[i]->GetA();
			Set* pClosure = Closure(pAs, S);
			if(!IsKey(pClosure, R)) {
				//define split variables
				Set* R1;
				Set* R2;
				std::vector<FunctionalDependency*> S1;
				std::vector<FunctionalDependency*> S2;

				//split relation and functional dependencies
				Split(R, S, R1, R2, S1, S2, pAs);

				//recursively call BCNF on the new relations and FD sets
				std::vector<Set*> pR1BCNF = BCNF(R1, S1);
				std::vector<Set*> pR2BCNF = BCNF(R2, S2);

				//merge sets of relations
				for (size_t i = 0; i < pR2BCNF.size(); i++) {
					pR1BCNF.push_back(pR2BCNF[i]);
				}

				//return the final set in BCNF
				return pR1BCNF;
			}
		}
	}
	//all keys checked out so return the relation we were given
	std::vector<Set*> pRelationSet;
	pRelationSet.push_back(R);
	return pRelationSet;
}

Set* BCNFCalculator::Closure(Set* Q, FDSet S) {
	Set* pC = new Set(Q); //build a new set to work with so we dont modify Q

	int pClosureSize;
	do{
		pClosureSize = pC->Size();
		for (size_t i = 0; i < S.size(); i++) { //look at each FD in S
			Set* pAs = S[i]->GetA();			//get the As
			Set* pBs = S[i]->GetB();			//get the Bs

			if(pAs->IsSubsetOf(pC)) {			//are the As a subset of the closure
				pC->Union(pBs);					//add to closure
			}
		}
	} while (pClosureSize != pC->Size());
	return pC;
}

bool BCNFCalculator::IsKey(Set* possibleKey, Set* relation) {return (relation->IsSubsetOf(possibleKey));}

void BCNFCalculator::Split(Set* R, FDSet S, Set*& R1, Set*& R2,  FDSet& S1, FDSet& S2, Set* problemAs){
	R1 = Closure (problemAs, S);
	R1->Intersect(R);
	R2 = new Set(R);
	R2->Subtract(R1);
	R2->Union(problemAs);

	SplitFDs(R, R1, S, S1);
	SplitFDs(R, R2, S, S2);
}

void BCNFCalculator::SplitFDs(Set* R, Set*& R1, FDSet S, FDSet& S1) {
	std::vector<Set*> pSubsets = GetAllSubsets(R1);

	for (int i = 0; i < pSubsets.size(); i++) {					//check each S for allowable
		Set* pAllowable = pSubsets[i];
		Set* pAllowableClosure = Closure(pAllowable, S);
		pAllowableClosure->Subtract(pAllowable);
		pAllowableClosure->Intersect(R1);

		for(size_t j = 0; j < pAllowableClosure->Size(); j++) {
			std::string pRawSet = pAllowable->ToRawSet();
			S1.push_back(new FunctionalDependency(pRawSet + " --> " + pAllowableClosure->Get(j)));
		}
	}
}


std::vector<Set*> BCNFCalculator::GetAllSubsets(Set* S) {
	std::vector<Set*> pSubsets;
	int numElements = S->Size();
	int numSubsets = numElements*numElements;

	Set* pNewSubset;
	for(int i = 1; i< numSubsets; i++){
		pNewSubset = new Set();
		bitset<32> x(i);
		std::ostringstream pTempOut;
		pTempOut << x;
		std::string pX = pTempOut.str();
		for (int q = 0; q < numElements; q++){
			std::string pTempString = std::string("") + pX[31 - q];
			std::istringstream pTempIn(pTempString);
			int oneOrZero;
			pTempIn >> oneOrZero;
			if (oneOrZero == 1) {
				pNewSubset->Union(new Set(S->Get(q)));
			}
		}
		pSubsets.push_back(pNewSubset);
	}
	return pSubsets;
}







