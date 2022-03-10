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

