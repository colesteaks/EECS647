#include "BCNFTester.h"
using namespace std;

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
	Set* pSet = new Set("EID PID Ename Pname Hours"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("EID --> Ename")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("PID --> Pname"));
	pS.push_back(new FunctionalDependency("EID PID--> Hours"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "TestA\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
	/*
	std::vector<Set*> pExpectedRelations;
	pExpectedRelations.push_back(new Set("EID Ename")); //ADDED EXPECTED RELATIONS
	pExpectedRelations.push_back(new Set("PID Pname"));
	pExpectedRelations.push_back(new Set("EID PID Hours"));
	RunSingleTest(calc, pSet, pS, pExpectedRelations, "Test A");*/
}

void BCNFTester::Test1a(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A --> B")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("A --> C"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1a\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::TestComp(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D E F G H I"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A --> C D E F G H")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("B --> I"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1a\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::Test1b(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A B --> C")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("C --> D"));
	pS.push_back(new FunctionalDependency("D --> A"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1b\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::Test1c(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("B --> C")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("B --> D"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1c\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::Test1d(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A B --> C")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("B C --> D"));
	pS.push_back(new FunctionalDependency("C D --> A"));
	pS.push_back(new FunctionalDependency("A D --> B"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1d\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::Test1e(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A --> B")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("B --> C"));
	pS.push_back(new FunctionalDependency("C --> D"));
	pS.push_back(new FunctionalDependency("D --> A"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1e\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::Test1f(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A B --> C D")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("C D --> A"));
	pS.push_back(new FunctionalDependency("A D --> B"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1f\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::Test1g(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D E"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A B --> C")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("D E --> C"));
	pS.push_back(new FunctionalDependency("B --> D"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1g\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::Test1h(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D E"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A --> C")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("C --> D"));
	pS.push_back(new FunctionalDependency("D --> E"));
	pS.push_back(new FunctionalDependency("E --> A"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1h\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::Test1i(BCNFCalculator* calc) {
	Set* pSet = new Set("A B C D E"); //this is where you add your set R
	std::vector<FunctionalDependency*> pS;
	pS.push_back(new FunctionalDependency("A B --> C")); //ADDED DEPENDENCIES
	pS.push_back(new FunctionalDependency("C --> D"));
	pS.push_back(new FunctionalDependency("D --> B E"));
	std::vector<Set*> pFinalRelations = calc->BCNF(pSet, pS);
	std::cout<< "Test1i\n";
	for(size_t i = 0; i < pFinalRelations.size(); i++) {
		cout << " > " << pFinalRelations[i]->ToString() << "\n";
	}
}

void BCNFTester::RunSingleTest(BCNFCalculator* calc, Set* R, FDSet S, std::vector<Set*>& expected, std::string title) {
	cout << "\n==================\nTitle:" << title << "\n";
	RunSingleTest(calc, R, S, expected);
}

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