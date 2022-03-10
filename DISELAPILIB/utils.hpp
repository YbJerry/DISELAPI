#pragma once

#include <iostream>
#include <vector>
#include <sstream>

namespace DISEL {
	enum class TYPE {
		Ontology,
		Atom,
		Edge,
		Concept,
		Graph
	};
}

inline std::vector<std::string> splitString(std::string str) {
	std::vector<std::string> res;
	std::istringstream istream(str);
	std::string s;
	while (istream >> s) {
		res.push_back(s);
	}
	return res;
}

inline std::string rptos(DISEL::RelationProperty rp) {
	switch (rp)
	{
	case DISEL::RelationProperty::transitive:
		return "transitive";
	case DISEL::RelationProperty::reflexive:
		return "reflexive";
	default:
		throw std::runtime_error("DISEL don't have this relation property");
		break;
	}
}