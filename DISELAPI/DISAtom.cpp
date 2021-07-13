#include "DISAtom.h"

DISEL::Atom::Atom()
{
}

DISEL::Atom::Atom(AtomTag name):name(name)
{
}

DISEL::Atom::Atom(AtomTag name, string description):name(name), description(description)
{
}

DISEL::AtomTag DISEL::Atom::getName() const
{
	return name;
}

void DISEL::Atom::setName(AtomTag name)
{
	this->name = name;
}

std::string DISEL::Atom::getDescription() const
{
	return description;
}

void DISEL::Atom::setDescription(string description)
{
	this->description = description;
}
