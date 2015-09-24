
#include "BCNFTester.h"
using namespace std;
void BCNFTester::RunTests(BCNFCalculator* calc) {
	TestA(calc);
	//TestB(calc);
	//TestWikipedia(calc);
}

void BCNFTester::TestA(BCNFCalculator* calc) {
	Set* pSet = new Set("EID PID Ename Pname Hours"); //this is where you add your set R
	vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("EID --> Ename")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("PID --> Pname"));
	pS.push_back(new FunctionalDependency("EID PID--> Hours"));
	vector<Set*> pExpectedRelations;
	pExpectedRelations.push_back(new Set("EID Ename")); //ADDED EXPECTED RELATIONS
	pExpectedRelations.push_back(new Set("PID Pname"));
	pExpectedRelations.push_back(new Set("EID PID Hours"));
	RunSingleTest(calc, pSet, pS, pExpectedRelations, "Test A");
}

void BCNFTester::TestB(BCNFCalculator* calc) {
	//add another relationship test
}

void BCNFTester::RunSingleTest(BCNFCalculator* calc, Set* R, FDSet S, vector<Set*>& expected, string title) {
	cout << "\n==================\nTitle:" << title << "\n";
	RunSingleTest(calc, R, S, expected);
}

void BCNFTester::RunSingleTest(BCNFCalculator* calc, Set* R, FDSet S, vector<Set*>& expected) {
	vector<Set*> pFinalRelations = calc->BCNF(R,S);
	if (pFinalRelations.size() != expected.size()) {
		cout << "Invalid size: " << pFinalRelations.size();
		cout << ", expected: " << (int)expected.size() << " relations. \n\n";
		for (size_t i = 0; i<pFinalRelations.size(); i++) {
			cout << "\tInvalid Relation: " << pFinalRelations[i]->ToString() << "\n";
		}
		return;
	}

	string pRelationToString;
	for (size_t i = 0; i < pFinalRelations.size(); i++) {
		bool isExpected = false;
		for(size_t j = 0; j<expected.size(); j++){
			if (pFinalRelations[i]->IsEqual(expected[j])) {
				isExpected = true;
				expected.erase(expected.begin() + j);
				break;
			}
		}
		if (!isExpected) {
			cout << "Invalid Relation: " << pFinalRelations[i]->ToString() << "\n";
			return;
		}
	}
	cout << "Test Passed!\nOutput: \n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}