#pragma once
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Set {
public:
	Set() {};
	~Set() {};
	Set(string spaceDelimitedSet);
	Set(Set* s);

	string Get(int index);
	void Intersect(Set* s);
	bool IsEqual(Set* relation);
	bool IsSubsetOf(Set* s);
	int Size();
	void Subtract(Set* s);
	string ToString();
	string ToRawSet();
	void Union(Set* s);
protected:
	bool VContains(string v);
	vector<string> Vunion(vector<string> s);
	bool VIsEqual(vector<string> s);
private:
	vector<string> mSet;
};