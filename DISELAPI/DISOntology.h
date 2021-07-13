#pragma once

#include <iostream>

#include "DISAtomDomain.h"
#include "DISConcept.h"
#include "DISGraph.h"

namespace DISEL {
	using namespace std;

	template<typename DISType>
	struct DISComp {
		bool operator()(const DISType& lhs, const DISType& rhs) const{
			return lhs.getName() < rhs.getName();
		}
	};

	class Ontology
	{
	public:
		Ontology();
		Ontology(string name);

		void setName(string name);
		string getName() const;
		void addAtom(Atom a);
		void addConcept(Concept c);
		void addGraph(Graph g);

	private:
		string name;
		AtomDomain atomDomain;
		set<Concept, DISComp<Concept>> concepts;
		set<Graph, DISComp<Graph>> graphs;
	};
}