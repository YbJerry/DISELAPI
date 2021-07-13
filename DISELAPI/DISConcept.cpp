#include "DISConcept.h"

DISEL::Concept::Concept()
{
}

DISEL::Concept::Concept(string name):name(name)
{
}

void DISEL::Concept::setName(string name)
{
	this->name = name;
}

std::string DISEL::Concept::getName() const
{
	return this->name;
}

DISEL::ConceptTag DISEL::Concept::getTag() const
{
	return name;
}

void DISEL::Concept::addAtomTypeLattice(AtomTag at)
{
	latticeOfConcepts.insert(at);
}

void DISEL::Concept::removeAtomTypeLattice(AtomTag at)
{
	latticeOfConcepts.erase(at);
}

std::vector<DISEL::AtomTag> DISEL::Concept::getLatticeOfConcepts()
{
	return vector<AtomTag>(latticeOfConcepts.begin(), latticeOfConcepts.end());
}

void DISEL::Concept::setDefination(string def)
{
	originalDefination = def;
}

std::string DISEL::Concept::getDefination() const
{
	return originalDefination;
}
