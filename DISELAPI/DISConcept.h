#pragma once

#include <iostream>
#include <set>
#include <vector>

#include "DISAtom.h"

namespace DISEL {
	using namespace std;

	typedef string ConceptTag;
	
	class Concept
	{
	public:
		Concept();
		Concept(string name);

		void setName(string name);
		string getName() const;
		ConceptTag getTag() const;
		void addAtomTypeLattice(AtomTag at);
		void removeAtomTypeLattice(AtomTag at);
		vector<AtomTag> getLatticeOfConcepts();
		void setDefination(string def);
		string getDefination() const;
		
	private:
		string name;
		set<AtomTag> latticeOfConcepts;
		string originalDefination;
	};
}

