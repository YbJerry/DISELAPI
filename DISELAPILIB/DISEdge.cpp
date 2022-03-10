#include "DISEdge.h"

DISEL::Edge::Edge(ConceptTag from, ConceptTag to):from(from), to(to)
{
}

void DISEL::Edge::setFromTag(ConceptTag ct)
{
	from = ct;
}

const DISEL::ConceptTag& DISEL::Edge::getFromTag() const
{
	return from;
}

DISEL::ConceptTag& DISEL::Edge::getFromTag() 
{
	return from;
}

void DISEL::Edge::setToTag(ConceptTag ct)
{
	to = ct;
}

const DISEL::ConceptTag& DISEL::Edge::getToTag() const
{
	return to;
}

DISEL::ConceptTag& DISEL::Edge::getToTag()
{
	return to;
}
