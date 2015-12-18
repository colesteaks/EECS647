#include "BCNFTester.h"
#include "BCNFCalculator.h"
using namespace std;

//main declares every BCNF helper objet required
//to perform the tests as  defined in the BCNFTester file. All results
//outputted to screen accordingly. 
int main() {
	BCNFTester* pTester = new BCNFTester();
	pTester->RunTests(new BCNFCalculator());
	string pWait;
	cin >> pWait;
	return 0;
}
