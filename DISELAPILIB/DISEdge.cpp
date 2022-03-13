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
