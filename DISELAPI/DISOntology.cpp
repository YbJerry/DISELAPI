#include "DISOntology.h"

DISEL::Ontology::Ontology()
{
}

DISEL::Ontology::Ontology(string name) :name(name)
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

void DISEL::Ontology::addAtoms(ConceptTag ct)
{
	if (find_if(concepts.begin(), concepts.end(), [ct](const Concept&) {}) != concepts.end())
}

std::vector<DISEL::Atom*> DISEL::Ontology::getAtomDomain()
{
	return atomDomain.getAllAtoms();
}

void DISEL::Ontology::addConcept(Concept c)
{
	concepts.insert(c);
}

std::optional<DISEL::Concept> DISEL::Ontology::getConcept(ConceptTag ct) const
{
	if (auto iter = find_if(concepts.begin(), concepts.end(), [ct](const Concept& con) {return con.getTag() == ct; }); iter != concepts.end()){
		return *iter;
	}
	return std::nullopt;
}

std::vector<DISEL::Concept> DISEL::Ontology::getAllConcepts() const
{
	return vector<Concept>(concepts.begin(), concepts.end());
}

void DISEL::Ontology::addGraph(Graph g)
{
	graphs.insert(g);
}

std::vector<DISEL::Graph> DISEL::Ontology::getAllGraphs() const
{
	return vector<Graph>(graphs.begin(), graphs.end());
}