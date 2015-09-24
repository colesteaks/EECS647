#include "Set.h"
using namespace std;

Set::Set(std::string spaceDelimitedSet) {
	std::string pAtomicValue;
	std::istringstream in(spaceDelimitedSet);

	while (in >> pAtomicValue) {
		mSet.push_back(pAtomicValue);
	}
}

Set::Set(Set* S) {mSet = S->VUnion(mSet);}
std::string Set::Get(int index) {return mSet[index];}

bool Set::IsSubsetOf(Set* s) {
	for (size_t i = 0; i<mSet.size(); i++) {
		if(!s->VContains(mSet[i])){
			return false;
		}
	}
	return true;
}

void Set::Intersect(Set* s){
	for (size_t i = 0; i < mSet.size(); i++) {
		if(!s->VContains(mSet[i])) {
			mSet.erase(mSet.begin() + i);
			i--;
		}
	}
}

bool Set::IsEqual(Set* relation) {return relation->VIsEqual(mSet);}
int Set::Size() { return (int)mSet.size();}

void Set::Subtract(Set* s) {
	for (size_t i = 0; i <mSet.size(); i++){
		if(s->VContains(mSet[i])){
			mSet.erase(mSet.begin() + i);
			i--;
		}	
	}
}

std::string Set::ToRawSet() {
	std::string outString;
	for(size_t i = 0; i<mSet.size(); i++) {
		outString = outString + mSet[i] + " ";
	}
	return outString;
}

std::string Set::ToString() { return "{ " + ToRawSet() + "}"; }
void Set::Union(Set* s) { mSet = s->VUnion(mSet); }

std::vector<std::string> Set::VUnion(std::vector<std::string> s) {
	std::vector<std::string> pUnion;
	for (std::string u : mSet) { //grab all our values
		pUnion.push_back(u);
	}
	for(std::string q : s) { // For each s check and see if its in our set
		if(!VContains(q)) { // if not then add it
			pUnion.push_back(q);
		}
	}
	return pUnion;
}

bool Set::VContains(std::string v) {
	for (std::string s : mSet) {
		if (s == v){
			return true;
		}
	}
	return false;
}

bool Set::VIsEqual(std::vector<std::string> s) {
	if (s.size() != mSet.size()) { return false;}
	for(size_t i = 0; i < s.size(); i++) {
		if (!VContains(s[i])) { return false; }
	}
	return true;
}









