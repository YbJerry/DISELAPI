#include "DISEdge.h"

DISEL::Edge::Edge(ConceptTag from, ConceptTag to):from(from), to(to)
{
}

void DISEL::Edge::setFromTag(ConceptTag ct)
{
	from = ct;
}

DISEL::ConceptTag DISEL::Edge::getFromTag() const
{
	return from;
}

void DISEL::Edge::setToTag(ConceptTag ct)
{
	to = ct;
}

DISEL::ConceptTag DISEL::Edge::getToTag() const
{
	return to;
}
