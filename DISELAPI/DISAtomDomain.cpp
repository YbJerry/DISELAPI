#include "DISAtomDomain.h"

DISEL::AtomDomain::AtomDomain()
{
}

void DISEL::AtomDomain::addAtom(Atom a)
{
	if (atoms.count(a.getName())) {
		throw runtime_error("atomDomain has already this atom");
	}
	atoms.insert({ a.getName(), a });
}

void DISEL::AtomDomain::removeAtom(AtomTag at)
{
	atoms.erase(at);
}

DISEL::Atom& DISEL::AtomDomain::getAtom(AtomTag at)
{
	if (!atoms.count(at)) {
		throw runtime_error("atomDomain doesn't have this atom");
	}

	return atoms[at];
}

std::vector<DISEL::Atom*> DISEL::AtomDomain::getAllAtoms()
{
	vector<Atom*> res;
	for (auto& [at, a] : atoms) {
		res.push_back(&a);
	}
	return res;
}
