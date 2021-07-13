#pragma once

#include <xercesc/dom/DOM.hpp>

inline XMLCh* stox(const char* str) {
	return xercesc::XMLString::transcode(str);
}

inline char* xtos(const XMLCh* xmlstr) {
	return xercesc::XMLString::transcode(xmlstr);
}