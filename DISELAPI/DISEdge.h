#pragma once

#include <iostream>

#include "DISConcept.h"

namespace DISEL {
	

	class Edge
	{
	public:
		Edge(ConceptTag from, ConceptTag to);

		void setFromTag(ConceptTag ct);
		ConceptTag getFromTag() const;
		void setToTag(ConceptTag ct);
		ConceptTag getToTag() const;

	private:
		ConceptTag from, to;
	};
}