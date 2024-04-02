/*
Sample code for vulnerable type: Improper Restriction of XML External Entity Reference
CWE : CWE-611
Description : the xml parser parses the data directly received from the user, here the setting of setDisableDefaultEntityResolution 
to true before parsing the user input would make the code secure.
*/
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <iostream>

const char* dosDtdContent = R"(
<!ENTITY dos "&dos;&dos;&dos;&dos;&dos;&dos;&dos;&dos;&dos;&dos;">
)";

void parseXmlData(const char* xmlData) {
    try {
        // Initialize Xerces-C++
        xercesc::XMLPlatformUtils::Initialize();

        // Create XercesDOMParser
        xercesc::XercesDOMParser *parser = new xercesc::XercesDOMParser();

        // Parse XML data
        parser->parse(xmlData); //sink

        // Get the document (unreachable in case of DoS)
        xercesc::DOMDocument* xmlDoc = parser->getDocument();

        // Cleanup
        delete parser;

        // Terminate Xerces-C++
        xercesc::XMLPlatformUtils::Terminate();
    } catch (const xercesc::XMLException& e) {
        std::cerr << "Exception: " << xercesc::XMLString::transcode(e.getMessage()) << std::endl;
    }
}

int main() {
    // Prompt user for XML data
    std::cout << "Enter XML data: ";
    std::string userXmlData;
    std::getline(std::cin, userXmlData); //source

    // Append DoS content to user-provided XML data
    userXmlData;

    // Parse user-provided XML data with potential DoS
    parseXmlData(userXmlData.c_str());

    return 0;
}
