#include "Set.h"
using namespace std;

//basic set constructor that takes in a space delimited string representing a set of
//variables and constructs a set of those variables
Set::Set(std::string spaceDelimitedSet) {
	std::string pAtomicValue;
	std::istringstream in(spaceDelimitedSet);

	while (in >> pAtomicValue) {
		mSet.push_back(pAtomicValue);
	}
}

//set constructor when passed a set object
Set::Set(Set* S) {mSet = S->VUnion(mSet);}

//returns member set variable in a set based on an index
std::string Set::Get(int index) {return mSet[index];}

//goes through every object in a sets member set, if
//both sets contain every object, then the set callin the function
//is a subset of the set passed through the function
bool Set::IsSubsetOf(Set* s) {
	for (size_t i = 0; i<mSet.size(); i++) {
		if(!s->VContains(mSet[i])){
			return false;
		}
	}
	return true;
}

//set logic implementation of intersection
void Set::Intersect(Set* s){
	for (size_t i = 0; i < mSet.size(); i++) {
		if(!s->VContains(mSet[i])) {
			mSet.erase(mSet.begin() + i);
			i--;
		}
	}
}

//set object test for equality
bool Set::IsEqual(Set* relation) {return relation->VIsEqual(mSet);}

//method to return size
int Set::Size() { return (int)mSet.size();}

//removes every elent in s from the set calling the method
void Set::Subtract(Set* s) {
	for (size_t i = 0; i <mSet.size(); i++){
		if(s->VContains(mSet[i])){
			mSet.erase(mSet.begin() + i);
			i--;
		}
	}
}

//creates a string of set variables
std::string Set::ToRawSet() {
	std::string outString;
	for(size_t i = 0; i<mSet.size(); i++) {
		outString = outString + mSet[i] + " ";
	}
	return outString;
}

//creates a string, utlizes raw set
std::string Set::ToString() { return "{ " + ToRawSet() + "}"; }

//basic set union operation
void Set::Union(Set* s) { mSet = s->VUnion(mSet); }

//more specificlaly defined union operation.
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

//function to check if a set contains a certain string v
bool Set::VContains(std::string v) {
	for (std::string s : mSet) {
		if (s == v){
			return true;
		}
	}
	return false;
}

//set operation to test for equality 
bool Set::VIsEqual(std::vector<std::string> s) {
	if (s.size() != mSet.size()) { return false;}
	for(size_t i = 0; i < s.size(); i++) {
		if (!VContains(s[i])) { return false; }
	}
	return true;
}
