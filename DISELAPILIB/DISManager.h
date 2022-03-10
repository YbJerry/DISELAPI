#pragma once

#include "DISOntology.h"

class DISManager
{
public:
	DISManager();
	DISEL::Ontology createOntology(std::string name);
	DISEL::Atom createAtom(std::string name, std::string description="");
private:
	std::vector<DISEL::Ontology> ontologies;
};

