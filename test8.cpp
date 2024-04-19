#include <iostream>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLString.hpp>

using namespace xercesc;

int main() {
    XMLPlatformUtils::Initialize();

    try {
        XercesDOMParser* parser = new XercesDOMParser();
        parser->parse("example.xml"); // BAD: parser is not correctly configured, may expand external entity references

        DOMDocument* xmlDoc = parser->getDocument();
        DOMElement* rootElement = xmlDoc->getDocumentElement();

        if (rootElement) {
            DOMNodeList* children = rootElement->getChildNodes();
            const XMLSize_t childCount = children->getLength();

            for (XMLSize_t i = 0; i < childCount; ++i) {
                DOMNode* childNode = children->item(i);
                if (childNode->getNodeType() == DOMNode::TEXT_NODE) {
                    XMLCh* xmlchValue = childNode->getNodeValue();
                    char* charValue = XMLString::transcode(xmlchValue);
                    std::cout << "Text: " << charValue << std::endl;
                    XMLString::release(&charValue);
                }
            }
        }

        parser->resetDocumentPool();
        delete parser;
    } catch (const XMLException& e) {
        char* message = XMLString::transcode(e.getMessage());
        std::cerr << "XMLException: " << message << std::endl;
        XMLString::release(&message);
    } catch (const DOMException& e) {
        char* message = XMLString::transcode(e.getMessage());
        std::cerr << "DOMException: " << message << std::endl;
        XMLString::release(&message);
    } catch (...) {
        std::cerr << "Unknown exception occurred." << std::endl;
    }

    XMLPlatformUtils::Terminate();
    return 0;
}
