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