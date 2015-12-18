#include "BCNFTester.h"
using namespace std;

//method to run all tests defined below
void BCNFTester::RunTests(BCNFCalculator* calc) {
	TestA(calc);
	Test1a(calc);
	TestComp(calc);
	Test1b(calc);
	Test1c(calc);
	Test1d(calc);
	Test1e(calc);
	Test1f(calc);
	Test1g(calc);
	Test1h(calc);
	Test1i(calc);
}


void BCNFTester::TestA(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D E F G H"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A --> B C D E F G H")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("G --> H"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS); //run normalization on defined pSet and pS
	std::cout<< "TestA\n"; //print test name
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n"; //print all final relations
	}
}

//run single test, passing in a title.
void BCNFTester::RunSingleTest(BCNFCalculator* calc, Set* R, FDSet S, std::vector<Set*>& expected, std::string title) {
	cout << "\n==================\nTitle:" << title << "\n";
	RunSingleTest(calc, R, S, expected);
}

//run a single test, passing in all necessary sets  and comparing to a vector set object "expected"
//to see if program is running correctly
void BCNFTester::RunSingleTest(BCNFCalculator* calc, Set* R, FDSet S, std::vector<Set*>& expected) {
	std::vector<Set*> pFinalRelations = calc->BCNF(R,S);
	if (pFinalRelations.size() != expected.size()) {
		cout << "Invalid size: " << pFinalRelations.size();
		cout << ", expected: " << (int)expected.size() << " relations. \n\n";
		for (size_t i = 0; i<pFinalRelations.size(); i++) {
			cout << "\tInvalid Relation: " << pFinalRelations[i]->ToString() << "\n";
		}
		return;
	}

	std::string pRelationToString;
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
