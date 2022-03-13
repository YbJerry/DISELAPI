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

#include "DISConcept.h"

DISEL::Concept::Concept()
{
}

DISEL::Concept::Concept(string name):name(name)
{
}

void DISEL::Concept::setName(string name)
{
	this->name = name;
}

std::string DISEL::Concept::getName() const
{
	return this->name;
}

DISEL::ConceptTag DISEL::Concept::getTag() const
{
	return name;
}

void DISEL::Concept::setDescription(string description)
{
	this->description = description;
}

std::string DISEL::Concept::getDescription() const
{
	return description;
}

void DISEL::Concept::addAtomTypeLattice(AtomTag at)
{
	latticeOfConcepts.insert(at);
}

void DISEL::Concept::removeAtomTypeLattice(AtomTag at)
{
	latticeOfConcepts.erase(at);
}

void DISEL::Concept::clearLatticeOfConcepts()
{
	latticeOfConcepts.clear();
}

std::vector<DISEL::AtomTag> DISEL::Concept::getLatticeOfConcepts() const
{
	return vector<AtomTag>(latticeOfConcepts.begin(), latticeOfConcepts.end());
}

void DISEL::Concept::setDefination(string def)
{
	originalDefination = def;
}

std::string DISEL::Concept::getDefination() const
{
	return originalDefination;
}

DISEL::ConceptTag::ConceptTag(std::string name):name(name), isFromOther(false)
{
}

DISEL::ConceptTag::ConceptTag(std::string name, std::string ontology):name(name), ontology(ontology), isFromOther(true)
{
}

std::string DISEL::ConceptTag::getName() const
{
	return name;
}

void DISEL::ConceptTag::setOntologyBelong(std::string ontology)
{
	isFromOther = true;
	this->ontology = ontology;
}

std::string DISEL::ConceptTag::getOntologyBelong() const
{
	return ontology;
}

bool DISEL::ConceptTag::fromOther() const
{
	return isFromOther;
}
