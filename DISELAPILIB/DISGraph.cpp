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
	nodes.insert(e.getFromTag());
	nodes.insert(e.getToTag());
	unattributableEdges.push_back(e);
}

void DISEL::Graph::addEdge(Edge e, RelationTag rt)
{
	nodes.insert(e.getFromTag());
	nodes.insert(e.getToTag());
	attributableEdges[rt].push_back(e);
}

void DISEL::Graph::addEdge(ConceptTag from, ConceptTag to)
{
	nodes.insert(from);
	nodes.insert(to);
	unattributableEdges.emplace_back(from, to);
}

void DISEL::Graph::addEdge(ConceptTag from, ConceptTag to, RelationTag rt)
{
	nodes.insert(from);
	nodes.insert(to);
	attributableEdges[rt].emplace_back(from, to);
}

void DISEL::Graph::addRelation(Relation r)
{
	relations.push_back(new Relation(r));
	attributableEdges.insert(std::make_pair(r.getName(), vector<Edge>()));
}

std::optional<DISEL::Relation*> DISEL::Graph::getRelation(RelationTag rt)
{
	if (auto iter = find_if(relations.begin(), relations.end(), [rt](Relation* rela) {return rela->getName() == rt; }); iter != relations.end()) {
		return *iter;
	}
	return std::nullopt;
}

void DISEL::Graph::delRelation(RelationTag rt)
{
	auto pred = [rt](Relation* rela) {return rela->getName() == rt;};
	if (auto iter = find_if(relations.begin(), relations.end(), pred); iter != relations.end()) {
		attributableEdges.erase(rt);
		delete* iter;
		relations.erase(iter);
	}
}

void DISEL::Graph::delUnattributableEdge(size_t index)
{
	if (index >= unattributableEdges.size()) {
		throw out_of_range("out_of_range in delUnattributableEdges");
	}
	unattributableEdges.erase(unattributableEdges.begin() + index);
}

void DISEL::Graph::delAttributableEdge(RelationTag rt, size_t index)
{
	if (attributableEdges.count(rt) == 0) {
		throw out_of_range("don't have this relation");
	}
	if ( index >= attributableEdges.at(rt).size()) {
		throw out_of_range("out_of_range in delAttributableEdges");
	}
	attributableEdges.at(rt).erase(attributableEdges.at(rt).begin() + index);
}

DISEL::Edge DISEL::Graph::getUnattributableEdge(size_t index)
{
	if (index >= unattributableEdges.size()) {
		throw out_of_range("out_of_range in getUnattributableEdges");
	}
	return *(unattributableEdges.begin() + index);
}

DISEL::Edge DISEL::Graph::getAttributableEdge(RelationTag rt, size_t index)
{
	if (attributableEdges.count(rt) == 0) {
		throw out_of_range("don't have this relation");
	}
	if (index >= attributableEdges.at(rt).size()) {
		throw out_of_range("out_of_range in getAttributableEdges");
	}
	return *(attributableEdges.at(rt).begin() + index);
}

std::vector<DISEL::Relation *> DISEL::Graph::getRelations() const
{
	return relations;
}

std::vector<DISEL::Edge> DISEL::Graph::getUnattributableEdges() const
{
	return unattributableEdges;
}

std::vector<std::pair<DISEL::RelationTag, std::vector<DISEL::Edge>>> DISEL::Graph::getAttributableEdges() const
{
	vector<pair<RelationTag, vector<Edge>>> res;
	for (auto [key, val] : attributableEdges) {
		res.push_back({ key, val });
	}
	return res;
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

std::vector<DISEL::ConceptTag> DISEL::Graph::getAllNodes() const
{
	return vector<ConceptTag>(nodes.begin(), nodes.end());
}
