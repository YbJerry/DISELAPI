#pragma once

#include <iostream>
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

#include <tinyxml2.h>

#include "DISOntology.h"
#include "utils.hpp"

class DISXMLWriter
{
public:
	DISXMLWriter();
	void write(std::string fileName, DISEL::Ontology& onto);

private:
	tinyxml2::XMLElement *readConceptFromDISEL(const DISEL::Concept& con, tinyxml2::XMLDocument &doc);
	tinyxml2::XMLElement* readGraphFromDISEL(const DISEL::Graph& gra, tinyxml2::XMLDocument& doc);
	tinyxml2::XMLElement* readEdgeFromDISEL(const DISEL::Edge& e, tinyxml2::XMLDocument& doc);
};

