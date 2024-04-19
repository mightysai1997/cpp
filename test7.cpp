#include "xercesc/sax2/SAX2XMLReader.hpp"

void parse() {
  SAX2XMLReader* reader = XMLReaderFactory::createXMLReader();
  reader->setFeature(XMLUni::fgXercesDisableDefaultEntityResolution, false); // Noncompliant

  reader->parse(xmlFile);
}
