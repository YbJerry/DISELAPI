#include "DISRelation.h"

DISEL::Relation::Relation()
{
	
}

DISEL::Relation::Relation(string name):name(name)
{
	
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

std::vector<DISEL::RelationProperty> DISEL::Relation::getAllProperties()
{
	return vector<RelationProperty>(properties.begin(), properties.end());
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
