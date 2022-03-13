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
#include <map>
#include <vector>
#include <optional>

#include "DISAtom.h"

namespace DISEL {
	using namespace std;

	class AtomDomain
	{
	public:
		AtomDomain();
		AtomDomain(const AtomDomain& ad);
		AtomDomain& operator=(const AtomDomain& ad);
		~AtomDomain();

		void addAtom(Atom a);
		void removeAtom(AtomTag at);
		optional<DISEL::Atom*> getAtom(AtomTag at);
		vector<Atom*> getAllAtoms();
	private:
		map<AtomTag, Atom*> atoms;
	};
}


