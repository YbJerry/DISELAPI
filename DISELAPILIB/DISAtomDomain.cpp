// Copyright[2022][Yijie Wang]
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http ://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissionsand
// limitations under the License.

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
