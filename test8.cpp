#include "libxml/parser.h"

void parse() {
  xmlDocPtr doc = xmlReadFile(xmlFile, nullptr, XML_PARSE_DTDLOAD | XML_PARSE_NOENT); // Noncompliant
}
