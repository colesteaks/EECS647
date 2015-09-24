#pragma once
#include "BCNFCalculator.h"
using namespace std;

class BCNFTester {
public:
	BCNFTester(){};
	~BCNFTester(){};
	void RunTests(BCNFCalculator* calc);
	void RunSingleTest(BCNFCalculator* calc, Set* R, FDSet S, vector<Set*>& expected);
	void RunSingleTest(BCNFCalculator* calc, Set* R, FDSet S, vector<Set*>& expected, string title);
	void TestA(BCNFCalculator* calc);
	//void TestB(BCNFCalculator* calc);
	//void TestWikipedia(BCNFCalculator* calc);
};