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

namespace DISEL {
	using namespace std;

	enum class RelationProperty { transitive, reflexive };

	const vector<RelationProperty> RelationPropertiesVec{ RelationProperty::transitive, RelationProperty::reflexive };

	class Relation
	{
		public:
			Relation();
			Relation(string name);
			Relation(const Relation& rela);
			Relation(Relation&& rela);
			Relation& operator=(const Relation& rela);

			void setName(string name);
			string getName() const;
			void addProperty(string p);
			void addProperty(RelationProperty p);
			void delProperty(RelationProperty p);
			vector<RelationProperty> getAllProperties() const;
			void clearProperties();

		private:
			RelationProperty storp(string p);

			string name;
			set<RelationProperty> properties;
	};
}


