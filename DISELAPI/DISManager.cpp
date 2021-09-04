#include "DISManager.h"

DISManager::DISManager()
{
}

DISEL::Ontology DISManager::createOntology(std::string name)
{
	return DISEL::Ontology(name);
}

DISEL::Atom DISManager::createAtom(std::string name, std::string description)
{
	DISEL::Atom atom(name);
	if (description.size()) {
		atom.setDescription(description);
	}
	return atom;
}
