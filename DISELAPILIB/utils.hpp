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