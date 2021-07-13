#include "DISGraph.h"

DISEL::Graph::Graph()
{
}

DISEL::Graph::Graph(string name) :name(name)
{
}

void DISEL::Graph::setName(string name)
{
	this->name = name;
}

std::string DISEL::Graph::getName() const
{
	return name;
}

void DISEL::Graph::setRoot(ConceptTag ct)
{
	root = ct;
}

DISEL::ConceptTag DISEL::Graph::getRoot() const
{
	return root;
}

void DISEL::Graph::addEdge(Edge e)
{
	edges.push_back(e);
}

void DISEL::Graph::addEdge(ConceptTag from, ConceptTag to)
{
	edges.emplace_back(from, to);
}

std::vector<DISEL::Edge> DISEL::Graph::getAllEdges() const
{
	return edges;
}
