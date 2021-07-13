#pragma once

#include <fstream>
#include <ranges>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>

#include "DISOntology.h"
#include "tools.hpp"

class DISXMLReader
{
public:
	DISXMLReader(std::string filePath);
	~DISXMLReader();
	DISEL::Ontology read();
private:
	xercesc::XercesDOMParser *parser;
};

