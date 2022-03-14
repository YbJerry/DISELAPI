// DISELAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "DISXMLReader.h"
#include "DISXMLWriter.h"

int main()
{
    DISXMLReader reader("./examples/onlyAtomDomain.xml");
    DISEL::Ontology *onto = reader.read();

    auto res = onto->getAtomDomain();

    DISXMLWriter writer;
    writer.write("test.xml", *onto);
    return 0;
}