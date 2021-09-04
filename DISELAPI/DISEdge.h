#pragma once

#include <iostream>

#include "DISConcept.h"

namespace DISEL {
	

	class Edge
	{
	public:
		Edge(ConceptTag from, ConceptTag to);

		void setFromTag(ConceptTag ct);
		const ConceptTag& getFromTag() const;
		ConceptTag& getFromTag();
		void setToTag(ConceptTag ct);
		const ConceptTag& getToTag() const;
		ConceptTag& getToTag();

	private:
		ConceptTag from, to;
	};
}