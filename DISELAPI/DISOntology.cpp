#include "DISOntology.h"

DISEL::Ontology::Ontology()
{
}

DISEL::Ontology::Ontology(string name):name(name)
{
}

void DISEL::Ontology::setName(string name)
{
	this->name = name;
}

std::string DISEL::Ontology::getName() const
{
	return name;
}

void DISEL::Ontology::addAtom(Atom a)
{
	atomDomain.addAtom(a);
}

void DISEL::Ontology::addConcept(Concept c)
{
	concepts.insert(c);
}

void DISEL::Ontology::addGraph(Graph g)
{
	graphs.insert(g);
}
