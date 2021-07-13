#pragma once

#include <iostream>

namespace DISEL {
	typedef std::string AtomTag;
	using namespace std;

	class Atom
	{
	public:
		Atom();
		Atom(AtomTag name);
		Atom(AtomTag name, string description);

		AtomTag getName() const;
		string getDescription() const;
		void setName(AtomTag name);
		void setDescription(string description);
	private:
		AtomTag name;
		string description;
	};

}

