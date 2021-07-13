#include "DISXMLReader.h"

DISXMLReader::DISXMLReader(std::string filePath)
{
	xercesc::XMLPlatformUtils::Initialize();
	parser = new xercesc::XercesDOMParser();
	parser->setDoNamespaces(true);
	parser->setDoSchema(true);
	parser->parse(filePath.c_str());
}

DISXMLReader::~DISXMLReader()
{
	delete parser;
	xercesc::XMLPlatformUtils::Terminate();
}

DISEL::Ontology DISXMLReader::read()
{
	DISEL::Ontology onto;

	auto *doc = parser->getDocument();

	auto *root = doc->getDocumentElement();
	auto *nameElement = root->getElementsByTagName(stox("name"))->item(0);
	onto.setName(xtos(nameElement->getTextContent()));
	auto *atomDomain = static_cast<xercesc::DOMElement *>(root->getElementsByTagName(stox("atomDomain"))->item(0));

	for (auto* a = atomDomain->getFirstElementChild(); a != nullptr; a = a->getNextElementSibling()) {
		onto.addAtom(DISEL::Atom(xtos(a->getTextContent()), xtos(a->getAttribute(stox("description")))));
	}

	// ce for concept XML element
	auto *ceList = root->getElementsByTagName(stox("concept"));
	if(ceList->getLength() > 0){
		for (auto* ce = static_cast<xercesc::DOMElement *>(ceList->item(0)); ce != nullptr; ce = ce->getNextElementSibling()) {
			auto *iter = ce->getFirstElementChild();
			// get concept name
			std::string name = xtos(ce->getFirstElementChild()->getTextContent());
			DISEL::Concept con(name);
		
			// get concept latticeOfConcepts
			iter = iter->getNextElementSibling();

			auto *cs = iter->getElementsByTagName(stox("concept"));
			for (int i = 0; i < cs->getLength(); ++i) {
				auto *ct = static_cast<xercesc::DOMElement*>(cs->item(i));
				con.addAtomTypeLattice(xtos(ct->getTextContent()));
			}

			auto *ats = iter->getElementsByTagName(stox("atoms"));
			for (int i = 0; i < ats->getLength(); ++i) {
				std::string atomsStr = xtos(static_cast<xercesc::DOMElement*>(ats->item(i))->getTextContent());
				// a C++20 new feature
				for (auto at : atomsStr 
								| std::ranges::views::split(' ') 
								| std::ranges::views::transform([](auto &&rng) {
									return std::string(&*rng.begin(), std::ranges::distance(rng));
								})) {
					con.addAtomTypeLattice(at);
				}
			}

			ats = iter->getElementsByTagName(stox("atom"));
			for (int i = 0; i < ats->getLength(); ++i) {
				std::string atomStr = xtos(static_cast<xercesc::DOMElement*>(ats->item(i))->getTextContent());
				con.addAtomTypeLattice(atomStr);
			}

			// get concept defination
			auto *defs = ce->getElementsByTagName(stox("defination"));
		
			if (defs->getLength() == 1) {
				std::string defStr = xtos(static_cast<xercesc::DOMElement*>(defs->item(0))->getTextContent());
				con.setDefination(defStr);
			}

			onto.addConcept(con);
		}
	}

	auto* ges = root->getElementsByTagName(stox("graph"));
	if (ges->getLength() > 0) {
		for (auto* ge = static_cast<xercesc::DOMElement*>(ges->item(0)); ge != nullptr; ge = ge->getNextElementSibling()) {
			auto *iter = ge->getFirstElementChild();
			std::string name = xtos(iter->getTextContent());
			DISEL::Graph gra(name);
			iter = iter->getNextElementSibling();
			gra.setRoot(xtos(iter->getTextContent()));
		}
	}

	return onto;
}
