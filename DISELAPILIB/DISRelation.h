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


