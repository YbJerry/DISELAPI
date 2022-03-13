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
#include <set>
#include <vector>

#include "DISAtom.h"

namespace DISEL {
	using namespace std;

	class ConceptTag {
		public:
			ConceptTag(string name);
			ConceptTag(string name, string ontology);

			std::string getName() const;
			void setOntologyBelong(std::string ontology);
			std::string getOntologyBelong() const;
			bool fromOther() const;
			bool operator==(const ConceptTag &ct) const {
				bool nameEqual = this->name == ct.name;
				bool ontoEqual = this->isFromOther == ct.isFromOther && (ct.isFromOther == false || ( ct.isFromOther == true && this->ontology == ct.ontology));
				return nameEqual && ontoEqual;
			}
			bool operator<(const ConceptTag& ct) const {
				bool cond1 = !this->isFromOther && !ct.isFromOther && this->name < ct.name;
				bool cond2 = !this->isFromOther && ct.isFromOther;
				bool cond3 = this->isFromOther && !ct.isFromOther && false;
				bool cond4 = this->isFromOther && ct.isFromOther && this->name < ct.name;
				return cond1 || cond2 || cond3 || cond4;
			}
		private:
			string name;
			bool isFromOther;
			string ontology;
	};
	
	class Concept
	{
	public:
		Concept();
		Concept(string name);

		void setName(string name);
		string getName() const;
		ConceptTag getTag() const;
		void setDescription(string description);
		string getDescription() const;
		void addAtomTypeLattice(AtomTag at);
		void removeAtomTypeLattice(AtomTag at);
		void clearLatticeOfConcepts();
		vector<AtomTag> getLatticeOfConcepts() const;
		void setDefination(string def);
		string getDefination() const;
		
	private:
		string name;
		string description;
		set<AtomTag> latticeOfConcepts;
		string originalDefination;
	};
}

