// DISELAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "DISXMLReader.h"

int main()
{
    DISXMLReader reader("dis.xml");
    reader.read();
}