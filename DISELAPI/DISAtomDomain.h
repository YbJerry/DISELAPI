#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "DISAtom.h"

namespace DISEL {
	using namespace std;

	class AtomDomain
	{
	public:
		AtomDomain();

		void addAtom(Atom a);
		void removeAtom(AtomTag at);
		Atom& getAtom(AtomTag at);
		vector<Atom*> getAllAtoms();
	private:
		map<AtomTag, Atom> atoms;
	};
}


