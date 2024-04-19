#include "xercesc/parsers/XercesDOMParser.hpp"

void parse() {
  XercesDOMParser *DOMparser = new XercesDOMParser();
  DOMparser->setCreateEntityReferenceNodes(false); // Noncompliant
  DOMparser->setDisableDefaultEntityResolution(false); // Noncompliant

  DOMparser->parse(xmlFile);
}
