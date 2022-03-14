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
	if (description.empty()) {
		hasDesc = false;
	}
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
