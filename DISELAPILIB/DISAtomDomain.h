#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <optional>

#include "DISAtom.h"

namespace DISEL {
	using namespace std;

	class AtomDomain
	{
	public:
		AtomDomain();
		AtomDomain(const AtomDomain& ad);
		AtomDomain& operator=(const AtomDomain& ad);
		~AtomDomain();

		void addAtom(Atom a);
		void removeAtom(AtomTag at);
		optional<DISEL::Atom*> getAtom(AtomTag at);
		vector<Atom*> getAllAtoms();
	private:
		map<AtomTag, Atom*> atoms;
	};
}


