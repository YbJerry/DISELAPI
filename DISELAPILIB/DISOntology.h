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

#pragma once

#include <iostream>

#include "DISAtomDomain.h"
#include "DISConcept.h"
#include "DISGraph.h"
#include <optional>

namespace DISEL {
	using namespace std;

	typedef string OntologyTag;

	template<typename DISType>
	struct DISComp {
		bool operator()(DISType* lhs, DISType* rhs) const{
			return lhs->getName() < rhs->getName();
		}
	};

	class Ontology
	{
	public:
		Ontology();
		Ontology(string name);
		Ontology(const Ontology& onto);
		Ontology& operator=(const Ontology& onto);
		~Ontology();

		void setName(string name);
		string getName() const;
		void addAtom(Atom a);
		void delAtom(AtomTag at);
		void addAtoms(ConceptTag ct);
		vector<Atom*> getAtomDomain();
		std::optional<Atom*> getAtom(AtomTag at);
		void addConcept(Concept *c);
		void delConcept(ConceptTag ct);
		std::optional<Concept *> getConcept(ConceptTag ct) const;
		vector<Concept*> getAllConcepts() const; 
		void addGraph(Graph *g);
		vector<Graph*> getAllGraphs() const;

	private:
		string name;
		AtomDomain atomDomain;
		set<Concept *, DISComp<Concept>> concepts;
		set<Graph *, DISComp<Graph>> graphs;
	};
}