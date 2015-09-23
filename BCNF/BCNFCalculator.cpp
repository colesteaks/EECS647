#include "BCNFCalculator.h"
using namespace std;

vector<Set*> BCNFCalculator::BCNF(Set* R, FDSet S) {
	if(S.size() > 0){
		for (size_t i = 0; i < S.size(); i++) {
			Set* pAs = S[i]->GetA();
			Set* pClosure = Closure(pAs, S);
			if(!IsKey(pClosure, R)) {
				//define split variables
				Set* R1;
				Set* R2;
				vector<FunctionalDependency*> S1;
				vector<FunctionalDependency*> S2;

				//split relation and functional dependencies
				Split(R, S, R1, R2, S1, S2, pAs);

				//recursively call BCNF on the new relations and FD sets
				vector<Set*> pR1BCNF = BCNF(R1, S1);
				vector<Set*> pR2BCNF = BCNF(R2, S2);

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
	vector<Set*> pRelationSet;
	pRelationSet.push_back(R);
	return pRelationSet;
}