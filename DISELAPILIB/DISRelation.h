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

			void setName(string name);
			string getName() const;
			void addProperty(string p);
			void addProperty(RelationProperty p);
			vector<RelationProperty> getAllProperties();

		private:
			RelationProperty storp(string p);

			string name;
			set<RelationProperty> properties;
	};
}


