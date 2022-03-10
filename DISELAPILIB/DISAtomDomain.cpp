#include "DISAtomDomain.h"

DISEL::AtomDomain::AtomDomain()
{
}

DISEL::AtomDomain::AtomDomain(const AtomDomain& ad)
{
	*this = ad;
}

DISEL::AtomDomain& DISEL::AtomDomain::operator=(const AtomDomain& ad)
{
	atoms = ad.atoms;
	return *this;
}

DISEL::AtomDomain::~AtomDomain()
{
	for (auto [_, p] : atoms) {
		delete p;
	}
}

void DISEL::AtomDomain::addAtom(Atom a)
{
	if (atoms.count(a.getName())) {
		throw runtime_error("atomDomain has already this atom");
	}
	Atom *at = new DISEL::Atom(std::move(a));
	atoms.insert({ at->getName(), at });
}

void DISEL::AtomDomain::removeAtom(AtomTag at)
{
	atoms.erase(at);
}

std::optional<DISEL::Atom *> DISEL::AtomDomain::getAtom(AtomTag at)
{
	if (atoms.count(at)) {
		return atoms[at];
	}

	return std::nullopt;
}

std::vector<DISEL::Atom*> DISEL::AtomDomain::getAllAtoms()
{
	vector<Atom*> res;
	for (auto& [at, a] : atoms) {
		res.push_back(a);
	}
	return res;
}
