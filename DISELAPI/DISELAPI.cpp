// DISELAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "DISXMLReader.h"
#include "DISXMLWriter.h"

int main()
{
    DISXMLReader reader("dis.xml");
    DISEL::Ontology onto = reader.read();

    DISXMLWriter writer;
    writer.write("test.xml", onto);
    return 0;
}