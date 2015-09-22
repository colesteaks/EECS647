#include "BCNFTester.h"
using namespace std;

int main() {
	BCNFTester* pTester = new BCNFTester();
	pTester->RunTests(new BCNFCalculator());
	string pWait;
	cin >> pWait;
	return 0;
}