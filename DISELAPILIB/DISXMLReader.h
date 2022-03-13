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

#pragma once

#include <fstream>
#include <ranges>
#include <tinyxml2.h>

#include "DISOntology.h"
#include "utils.hpp"
#include "DISAtom.h"
#include "DISConcept.h"

class DISXMLReader
{
public:
	DISXMLReader(std::string filePath);
	~DISXMLReader();
	DISEL::Ontology* read();
private:
	DISEL::Atom readAtomFromXML(tinyxml2::XMLElement* e);
	DISEL::Concept* readConceptFromXML(tinyxml2::XMLElement* e, DISEL::Ontology* onto);
	DISEL::Graph* readGraphFromXML(tinyxml2::XMLElement* e);
	DISEL::AtomDomain readAtomDomainFromXML(tinyxml2::XMLElement *e);

	tinyxml2::XMLDocument doc;
};

