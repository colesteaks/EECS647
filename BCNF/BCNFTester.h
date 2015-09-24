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
	void Test1a(BCNFCalculator* calc);
	void Test1b(BCNFCalculator* calc);
	void Test1c(BCNFCalculator* calc);
	void Test1d(BCNFCalculator* calc);
	void Test1e(BCNFCalculator* calc);
	void Test1f(BCNFCalculator* calc);
	void Test1g(BCNFCalculator* calc);
	void Test1h(BCNFCalculator* calc);
	void Test1i(BCNFCalculator* calc);
	void TestA(BCNFCalculator* calc);
	//void TestWikipedia(BCNFCalculator* calc);
};