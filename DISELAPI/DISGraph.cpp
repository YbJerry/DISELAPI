#include "DISGraph.h"

DISEL::Graph::Graph():root(nullptr)
{
}

DISEL::Graph::Graph(const Graph& g):
	name(g.name),
	root(new ConceptTag(g.getRoot().getName())),
	unattributableEdges(g.unattributableEdges),
	attributableEdges(g.attributableEdges),
	relations(g.relations)
{

}

DISEL::Graph::Graph(Graph&& g):
	name(g.name),
	root(g.root),
	unattributableEdges(g.unattributableEdges),
	attributableEdges(g.attributableEdges),
	relations(g.relations)
{
	g.root = nullptr;
}

DISEL::Graph::Graph(string name) :name(name), root(nullptr)
{
}

DISEL::Graph::~Graph()
{
	delete root;
}

void DISEL::Graph::setName(string name)
{
	this->name = name;
}

std::string DISEL::Graph::getName() const
{
	return name;
}

void DISEL::Graph::setRoot(string rootName)
{
	root = new ConceptTag(rootName);
}

DISEL::ConceptTag DISEL::Graph::getRoot() const
{
	return *root;
}

void DISEL::Graph::addEdge(Edge e)
{
	unattributableEdges.push_back(e);
}

void DISEL::Graph::addEdge(Edge e, RelationTag rt)
{
	attributableEdges[rt].push_back(e);
}

void DISEL::Graph::addEdge(ConceptTag from, ConceptTag to)
{
	unattributableEdges.emplace_back(from, to);
}

void DISEL::Graph::addEdge(ConceptTag from, ConceptTag to, RelationTag rt)
{
	attributableEdges[rt].emplace_back(from, to);
}

void DISEL::Graph::addRelation(Relation r)
{
	relations.push_back(r);
	attributableEdges.insert(std::make_pair(r.getName(), vector<Edge>()));
}

std::vector<DISEL::Relation> DISEL::Graph::getRelations() const
{
	return relations;
}

std::vector<DISEL::Edge> DISEL::Graph::getUnattributableEdges() const
{
	return unattributableEdges;
}

std::vector<DISEL::Edge> DISEL::Graph::getEdgesFromRelation(RelationTag rt) const
{
	return attributableEdges.at(rt);
}

std::vector<DISEL::Edge> DISEL::Graph::getAllEdges() const
{
	vector<Edge> res = getUnattributableEdges();
	for (auto [_, vecEdge] : attributableEdges) {
		for (auto e : vecEdge) {
			res.push_back(e);
		}
	}
	return res;
}
