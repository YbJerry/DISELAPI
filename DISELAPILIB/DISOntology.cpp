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

#include "DISOntology.h"

DISEL::Ontology::Ontology()
{
}

DISEL::Ontology::Ontology(string name) :name(name)
{
}

DISEL::Ontology::Ontology(const Ontology& onto)
{
	*this = onto;
}

DISEL::Ontology& DISEL::Ontology::operator=(const Ontology& onto)
{
	name = onto.name;
	atomDomain = onto.atomDomain;
	concepts = onto.concepts;
	graphs = onto.graphs;
	return *this;
}

DISEL::Ontology::~Ontology()
{
	for (auto con : concepts) {
		delete con;
	}

	for (auto gra : graphs) {
		delete gra;
	}
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

void DISEL::Ontology::delAtom(AtomTag at)
{
	atomDomain.removeAtom(at);
	for (auto &con : concepts) {
		con->removeAtomTypeLattice(at);
	}
}

std::vector<DISEL::Atom*> DISEL::Ontology::getAtomDomain()
{
	return atomDomain.getAllAtoms();
}

std::optional<DISEL::Atom*> DISEL::Ontology::getAtom(AtomTag at)
{
	return atomDomain.getAtom(at);
}

void DISEL::Ontology::addConcept(Concept* c)
{
	concepts.insert(c);
}

void DISEL::Ontology::delConcept(ConceptTag ct)
{
	for (auto iter = concepts.begin(); iter != concepts.end();) {
		if ((*iter)->getTag() == ct) {
			concepts.erase(iter);
		}
		else {
			++iter;
		}
	}
}

std::optional<DISEL::Concept *> DISEL::Ontology::getConcept(ConceptTag ct) const
{
	if (auto iter = find_if(concepts.begin(), concepts.end(), [ct](Concept* con) {return con->getTag() == ct; }); iter != concepts.end()){
		return *iter;
	}
	return std::nullopt;
}

std::vector<DISEL::Concept *> DISEL::Ontology::getAllConcepts() const
{
	return vector<Concept *>(concepts.begin(), concepts.end());
}

void DISEL::Ontology::addGraph(Graph* g)
{
	graphs.insert(g);
}

std::vector<DISEL::Graph *> DISEL::Ontology::getAllGraphs() const
{
	return vector<Graph *>(graphs.begin(), graphs.end());
}