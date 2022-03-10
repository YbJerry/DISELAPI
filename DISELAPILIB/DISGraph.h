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

	struct CtComp {
		bool operator()(const ConceptTag& lhs, const ConceptTag& rhs) const {
			return lhs.getName() < rhs.getName();
		}
	};

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
		void delRelation(RelationTag rt);
		void delUnattributableEdge(size_t index);
		void delAttributableEdge(RelationTag rt, size_t index);
		Edge getUnattributableEdge(size_t index);
		Edge getAttributableEdge(RelationTag rt, size_t index);
		vector<Relation> getRelations() const;
		vector<Edge> getUnattributableEdges() const;
		vector<pair<RelationTag, vector<Edge>>> getAttributableEdges() const;
		vector<Edge> getEdgesFromRelation(RelationTag rt) const;
		vector<Edge> getAllEdges() const;
		vector<ConceptTag> getAllNodes() const;

	private:
		string name;
		ConceptTag *root;
		vector<Edge> unattributableEdges;
		set<ConceptTag> nodes;
		map<RelationTag, vector<Edge>> attributableEdges;
		vector<Relation> relations;
	};
}