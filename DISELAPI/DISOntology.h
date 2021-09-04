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
		void addAtoms(ConceptTag ct);
		vector<Atom*> getAtomDomain();
		void addConcept(Concept c);
		std::optional<Concept> getConcept(ConceptTag ct) const;
		vector<Concept> getAllConcepts() const; 
		void addGraph(Graph g);
		vector<Graph> getAllGraphs() const;

	private:
		string name;
		AtomDomain atomDomain;
		set<Concept, DISComp<Concept>> concepts;
		set<Graph, DISComp<Graph>> graphs;
	};
}