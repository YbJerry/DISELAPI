#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "DISConcept.h"
#include "DISEdge.h"
#include "DISRelation.h"

namespace DISEL {
	using namespace std;

	typedef string EdgeTag;
	typedef string RelationTag;

	class Graph
	{
	public:
		Graph();
		Graph(const Graph& g);
		Graph(Graph &&g);
		Graph(string name);
		~Graph();
		void setName(string name);
		string getName() const;
		void setRoot(string rootName);
		ConceptTag getRoot() const;
		void addEdge(Edge e);
		void addEdge(Edge e, RelationTag rt);
		void addEdge(ConceptTag from, ConceptTag to);
		void addEdge(ConceptTag from, ConceptTag to, RelationTag rt);
		void addRelation(Relation r);
		vector<Relation> getRelations() const;
		vector<Edge> getUnattributableEdges() const;
		vector<Edge> getEdgesFromRelation(RelationTag rt) const;
		vector<Edge> getAllEdges() const;

	private:
		string name;
		ConceptTag *root;
		vector<Edge> unattributableEdges;
		map<RelationTag, vector<Edge>> attributableEdges;
		vector<Relation> relations;
	};
}