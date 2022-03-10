#include "DISXMLReader.h"

DISXMLReader::DISXMLReader(std::string filePath):doc(true, tinyxml2::COLLAPSE_WHITESPACE)
{
	doc.LoadFile(filePath.c_str());
}

DISXMLReader::~DISXMLReader()
{
}

DISEL::Ontology* DISXMLReader::read()
{
	DISEL::Ontology* onto = new DISEL::Ontology();

	auto *root = doc.FirstChildElement("ontology");
	
	auto *ontoNameElement = root->FirstChildElement("name");
	if (ontoNameElement != nullptr) {
		onto->setName(root->FirstChildElement("name")->GetText());
	}
	else {
		throw std::runtime_error("ontology doesn't contain a name element");
	}
	auto *atomDomain = root->FirstChildElement("atomDomain");

	for (auto* it = atomDomain->FirstChildElement(); it != nullptr; it = it->NextSiblingElement()) {
		if (strcmp(it->Name(), "atom") == 0) {
			onto->addAtom(readAtomFromXML(it));
		}
		else {
			throw std::runtime_error("atomDomain contains elements besides atom elements");
		}
	}

	for (auto* it = root->FirstChildElement("concept"); it != nullptr; it = it->NextSiblingElement("concept")) {
		onto->addConcept(readConceptFromXML(it, onto));
	}

	for (auto* it = root->FirstChildElement("graph"); it != nullptr; it = it->NextSiblingElement("graph")) {
		onto->addGraph(readGraphFromXML(it));
	}

	return onto;
}

DISEL::Atom DISXMLReader::readAtomFromXML(tinyxml2::XMLElement* e)
{
	DISEL::Atom res;
	if (e->FirstChildElement("name") != nullptr) {
		res.setName(e->FirstChildElement("name")->GetText());
	}
	else {
		throw std::runtime_error("atom don't have a name");
	}

	if (e->FirstChildElement("description") != nullptr) {
		res.setDescription(e->FirstChildElement("description")->GetText());
	}
	return res;
	
}

DISEL::Concept* DISXMLReader::readConceptFromXML(tinyxml2::XMLElement* e, DISEL::Ontology *onto)
{
	DISEL::Concept *con = new DISEL::Concept();

	// read name of concept
	if (auto* conNameElement = e->FirstChildElement("name"); conNameElement != nullptr) {
		con->setName(conNameElement->GetText());
	}
	else {
		throw std::runtime_error("concept doesn't contain a name element");
	}

	// read latticeOfConcepts of concept
	if (auto* conLatticeElement = e->FirstChildElement("latticeOfConcepts"); conLatticeElement != nullptr) {
		for (auto* it = conLatticeElement->FirstChildElement("atom"); it != nullptr; it = it->NextSiblingElement("atom")) {
			con->addAtomTypeLattice(it->GetText());
		}

		for (auto* it = conLatticeElement->FirstChildElement("atoms"); it != nullptr; it = it->NextSiblingElement("atoms")) {
			std::string atomsStr = it->GetText();
			auto atoms = splitString(atomsStr);
			for (auto a : atoms) {
				con->addAtomTypeLattice(a);
			}
		}

		for (auto* it = conLatticeElement->FirstChildElement("concept"); it != nullptr; it = it->NextSiblingElement("concept")) {
			std::string conTagStr = it->GetText();
			if (auto ctCon = onto->getConcept(DISEL::ConceptTag(conTagStr)); ctCon != std::nullopt) {
				for (auto l : ctCon.value()->getLatticeOfConcepts()) {
					con->addAtomTypeLattice(l);
				}
			}
			else {
				throw std::runtime_error("this concept tag doesn't exist");
			}
		}
	}
	else {
		throw std::runtime_error("concept doesn't contain a latticeOfConcepts element");
	}

	// read defination of concept
	if (auto* conDefElement = e->FirstChildElement("defination"); conDefElement != nullptr) {
		con->setDefination(conDefElement->GetText());
	}

	// read description of concept
	if (auto* conDescElement = e->FirstChildElement("description"); conDescElement != nullptr) {
		con->setDescription(conDescElement->GetText());
	}

	return con;
}

DISEL::Graph* DISXMLReader::readGraphFromXML(tinyxml2::XMLElement* e)
{
	DISEL::Graph* gra = new DISEL::Graph();

	// read name of graph
	if (auto* conNameElement = e->FirstChildElement("name"); conNameElement != nullptr) {
		gra->setName(conNameElement->GetText());
	}
	else {
		throw std::runtime_error("graph doesn't contain a name element");
	}

	// read root of graph
	if (auto* conRootElement = e->FirstChildElement("rootedIn"); conRootElement != nullptr) {
		gra->setRoot(conRootElement->GetText());
	}
	else {
		throw std::runtime_error("graph doesn't contain a rootedIn element");
	}

	// read unattribute edges of graph
	for (auto* it = e->FirstChildElement("edge"); it != nullptr; it = it->NextSiblingElement("edge")) {
		if (auto* fromElement = it->FirstChildElement("from"), * toElement = it->FirstChildElement("to");
				fromElement != nullptr && toElement != nullptr) {
			DISEL::ConceptTag from(fromElement->GetText()), to(toElement->GetText());
			if (auto* dis = fromElement->Attribute("DIS"); dis != nullptr) {
				from.setOntologyBelong(dis);
			}
			if (auto* dis = toElement->Attribute("DIS"); dis != nullptr) {
				to.setOntologyBelong(dis);
			}
			gra->addEdge(from, to);
		}
		else{
			throw std::runtime_error("edge doesn't contain a from or to element");
		}
	}

	// read relation of graph
	for (auto* itRela = e->FirstChildElement("relation"); itRela != nullptr; itRela = itRela->NextSiblingElement("relation")) {
		DISEL::Relation rela;
		// read name of relation
		if (auto* nameElement = itRela->FirstChildElement("name"); nameElement != nullptr) {
			rela.setName(nameElement->GetText());
		}
		else {
			throw std::runtime_error("relation doesn't contain a name element");
		}

		// read properties of relation
		if (auto* propElement = itRela->FirstChildElement("properties"); propElement != nullptr) {
			auto propStrs = splitString(propElement->GetText());
			for (auto str : propStrs) {
				rela.addProperty(str);
			}
		}

		gra->addRelation(rela);

		// read unattribute edges of graph
		for (auto* it = itRela->FirstChildElement("edge"); it != nullptr; it = it->NextSiblingElement("edge")) {
			if (auto* fromElement = it->FirstChildElement("from"), *toElement = it->FirstChildElement("to");
				fromElement != nullptr && toElement != nullptr) {
				DISEL::ConceptTag from(fromElement->GetText()), to(toElement->GetText());
				if (auto* dis = fromElement->Attribute("DIS"); dis != nullptr) {
					from.setOntologyBelong(dis);
				}
				if (auto* dis = toElement->Attribute("DIS"); dis != nullptr) {
					to.setOntologyBelong(dis);
				}
				gra->addEdge(from, to, rela.getName());
			}
			else {
				throw std::runtime_error("edge doesn't contain a from or to element");
			}
		}
	}

	return gra;
}

DISEL::AtomDomain DISXMLReader::readAtomDomainFromXML(tinyxml2::XMLElement* e)
{
	DISEL::AtomDomain res;
	for (auto* it = e->FirstChildElement(); it != nullptr; it = it->NextSiblingElement()) {
		if (strcmp(it->Name(), "atom") == 0) {
			res.addAtom(readAtomFromXML(it));
		}
		else {
			throw std::runtime_error("atomDomain contains elements besides atom elements");
		}
	}
	return DISEL::AtomDomain();
}