#include "xercesc/parsers/SAXParser.hpp"

void parse() {
  SAXParser* SAXparser = new SAXParser();
  SAXparser->setDisableDefaultEntityResolution(false); // Noncompliant

  SAXparser->parse(xmlFile);
}
