#pragma once

#include <iostream>
#include <tinyxml2.h>

#include "DISOntology.h"
#include "utils.hpp"

class DISXMLWriter
{
public:
	DISXMLWriter();
	void write(std::string fileName, DISEL::Ontology);

private:
	tinyxml2::XMLElement *readConceptFromDISEL(const DISEL::Concept& con, tinyxml2::XMLDocument &doc);
	tinyxml2::XMLElement* readGraphFromDISEL(const DISEL::Graph& gra, tinyxml2::XMLDocument& doc);
	tinyxml2::XMLElement* readEdgeFromDISEL(const DISEL::Edge& e, tinyxml2::XMLDocument& doc);
};

