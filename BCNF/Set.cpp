#include "Set.h"


Set::Set(string spaceDelimitedSet) {
	string pAtomicValue;
	istringstream in(spaceDelimitedSet);

	while (in >> pAtomicValue) {
		mSet.push_back(pAtomicValue);
	}
}

Set::Set(Set* S) {mSet = S->VUnion(mSet);}
string Set::Get(int index) {return mSet[index];}

bool Set::IsSubsetOf(Set* s) {
	for (size_t i = 0; i<mSet.size(); i++) {
		if(!s->VContains(mSet[i])){
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

string Set::ToRawSet() {
	string outString;
	for(size_t i = 0; i<mSet.size(); i++) {
		outString = outString + mSet[i] + " ";
	}
	return outString;
}

string Set::ToString() { return "{ " + ToRawSet() + "}"; }
void Set::Union(Set* s) { mSet = s->VUnion(mSet); }

vector<string> Set::VUnion(vector<string> s) {
	vector<string> pUnion;
	for (string u : mSet) { //grab all our values
		pUnion.push_back(u);
	}
	for(string q : s) { // For each s check and see if its in our set
		if(!VContains(q)) { // if not then add it
			pUnion.push_back(q);
		}
	}
	return pUnion;
}

bool Set::VContains(string v) {
	for (string s : mSet) {
		if (s == v){
			return true;
		}
	}
	return false;
}

bool Set::VIsEqual(vector<string> s) {
	if (s.size() != mSet.size()) { return false;}
	for(size_t i = 0; i < s.size(); i++) {
		if (!VContains(s[i])) { return false; }
	}
	return true;
}









