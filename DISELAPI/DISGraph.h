#pragma once

#include <iostream>
#include <vector>

#include "DISConcept.h"
#include "DISEdge.h"

namespace DISEL {
	using namespace std;

	typedef string EdgeTag;

	class Graph
	{
	public:
		Graph();
		Graph(string name);
		void setName(string name);
		string getName() const;
		void setRoot(ConceptTag ct);
		ConceptTag getRoot() const;
		void addEdge(Edge e);
		void addEdge(ConceptTag from, ConceptTag to);
		vector<Edge> getAllEdges() const;

	private:
		string name;
		ConceptTag root;
		vector<Edge> edges;
		vector<Rela
	};
}