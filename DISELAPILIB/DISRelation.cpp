#include "DISRelation.h"

DISEL::Relation::Relation()
{
	
}

DISEL::Relation::Relation(string name):name(name)
{
	
}

DISEL::Relation::Relation(const Relation& rela): name(rela.name), properties(rela.properties)
{

}

DISEL::Relation::Relation(Relation&& rela) : name(move(rela.name)), properties(move(rela.properties))
{
}

DISEL::Relation& DISEL::Relation::operator=(const Relation& rela)
{
	name = rela.name;
	properties = rela.properties;
	return *this;
}

void DISEL::Relation::setName(string name)
{
	this->name = name;
}

std::string DISEL::Relation::getName() const
{
	return name;
}

void DISEL::Relation::addProperty(string p)
{
	addProperty(storp(p));
}

void DISEL::Relation::addProperty(RelationProperty p)
{
	properties.insert(p);
}

void DISEL::Relation::delProperty(RelationProperty p)
{
	properties.erase(p);
}

std::vector<DISEL::RelationProperty> DISEL::Relation::getAllProperties() const
{
	return vector<RelationProperty>(properties.begin(), properties.end());
}

void DISEL::Relation::clearProperties()
{
	properties.clear();
}

DISEL::RelationProperty DISEL::Relation::storp(string p)
{
	if (p == "transitive") {
		return RelationProperty::transitive;
	}
	else if(p == "reflexive") {
		return RelationProperty::reflexive;
	}
	else {
		throw std::runtime_error("unknown property");
	}
}
