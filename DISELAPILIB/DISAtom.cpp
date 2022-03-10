#include "DISAtom.h"

DISEL::Atom::Atom():hasDesc(false)
{
}

DISEL::Atom::Atom(const Atom& at):name(at.name), hasDesc(at.hasDesc), description(at.description)
{

}

DISEL::Atom::Atom(Atom&& at):name(std::move(at.name)), hasDesc(at.hasDesc), description(std::move(at.description))
{
}

DISEL::Atom::Atom(AtomTag name):name(name), hasDesc(false)
{
}

DISEL::Atom::Atom(AtomTag name, string description):name(name), description(description), hasDesc(true)
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
	hasDesc = true;
	this->description = description;
}

void DISEL::Atom::delDescription()
{
	description.clear();
	hasDesc = false;
}

bool DISEL::Atom::hasDescription() const
{
	return hasDesc;
}
