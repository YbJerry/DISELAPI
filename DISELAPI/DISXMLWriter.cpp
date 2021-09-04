#include "DISXMLWriter.h"

DISXMLWriter::DISXMLWriter()
{
}

void DISXMLWriter::write(std::string fileName, DISEL::Ontology onto)
{
	tinyxml2::XMLDocument doc;

	doc.InsertFirstChild(doc.NewDeclaration());

	auto *ontologyElement = doc.NewElement("ontology");
	
	auto *nameElement = doc.NewElement("name");
	nameElement->SetText(onto.getName().c_str());
	ontologyElement->InsertEndChild(nameElement);

	auto *atomDomainElement = doc.NewElement("atomDomain");
	for (auto pa : onto.getAtomDomain()) {
		auto *atomElement = doc.NewElement("atom");

		auto *nameElement = doc.NewElement("name");
		nameElement->SetText(pa->getName().c_str());
		atomElement->InsertEndChild(nameElement);

		if (pa->hasDescription()) {
			auto* descElement = doc.NewElement("description");
			descElement->SetText(pa->getDescription().c_str());
			atomElement->InsertEndChild(descElement);
		}
		atomDomainElement->InsertEndChild(atomElement);
	}
	ontologyElement->InsertEndChild(atomDomainElement);

	for (auto c : onto.getAllConcepts()) {
		ontologyElement->InsertEndChild(readConceptFromDISEL(c, doc));
	}

	for (auto g : onto.getAllGraphs()) {
		ontologyElement->InsertEndChild(readGraphFromDISEL(g, doc));
	}

	doc.InsertEndChild(ontologyElement);

	doc.SaveFile(fileName.c_str());
}

tinyxml2::XMLElement* DISXMLWriter::readConceptFromDISEL(const DISEL::Concept& con, tinyxml2::XMLDocument &doc)
{
	auto* conElement = doc.NewElement("concept");

	auto* nameElement = doc.NewElement("name");
	nameElement->SetText(con.getName().c_str());
	conElement->InsertEndChild(nameElement);

	auto* latticeElement = doc.NewElement("latticeOfConcepts");
	for (auto l : con.getLatticeOfConcepts()) {
		auto* atomTagElement = doc.NewElement("atom");
		atomTagElement->SetText(l.c_str());
		latticeElement->InsertEndChild(atomTagElement);
	}

	conElement->InsertEndChild(latticeElement);
	return conElement;
}

tinyxml2::XMLElement* DISXMLWriter::readGraphFromDISEL(const DISEL::Graph& gra, tinyxml2::XMLDocument& doc)
{
	auto* graElement = doc.NewElement("graph");

	auto* nameElement = doc.NewElement("name");
	nameElement->SetText(gra.getName().c_str());
	graElement->InsertEndChild(nameElement);

	auto* rootElement = doc.NewElement("rootedIn");
	rootElement->SetText(gra.getRoot().getName().c_str());
	graElement->InsertEndChild(rootElement);

	for (auto ue : gra.getUnattributableEdges()) {
		graElement->InsertEndChild(readEdgeFromDISEL(ue, doc));
	}

	for (auto r : gra.getRelations()) {
		auto* relaElement = doc.NewElement("relation");

		auto* relaNameElement = doc.NewElement("name");
		relaNameElement->SetText(r.getName().c_str());
		relaElement->InsertEndChild(relaNameElement);

		auto* propElement = doc.NewElement("properties");
		std::string propStr;
		for (auto rp : r.getAllProperties()) {
			propStr += rptos(rp) + " ";
		}
		propElement->SetText(propStr.c_str());
		relaElement->InsertEndChild(propElement);

		for (auto e : gra.getEdgesFromRelation(r.getName())) {
			relaElement->InsertEndChild(readEdgeFromDISEL(e, doc));
		}
		graElement->InsertEndChild(relaElement);
	}

	return graElement;
}

tinyxml2::XMLElement* DISXMLWriter::readEdgeFromDISEL(const DISEL::Edge& e, tinyxml2::XMLDocument& doc)
{
	auto* edgeElement = doc.NewElement("edge");

	auto* fromElement = doc.NewElement("from");
	const auto &ft = e.getFromTag();
	fromElement->SetText(ft.getName().c_str());
	if (ft.fromOther()) {
		fromElement->SetAttribute("DIS", ft.getOntologyBelong().c_str());
	}
	edgeElement->InsertEndChild(fromElement);

	auto* toElement = doc.NewElement("to");
	const auto& tt = e.getToTag();
	toElement->SetText(tt.getName().c_str());
	if (tt.fromOther()) {
		toElement->SetAttribute("DIS", tt.getOntologyBelong().c_str());
	}
	edgeElement->InsertEndChild(toElement);

	return edgeElement;
}
