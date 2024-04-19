#include <iostream>
#include "tinyxml2.h"

int main() {
    std::string data;
    std::cin >> data;

    tinyxml2::XMLDocument doc;
    doc.UseExternalEntities(false); // Disable external entities
    if (doc.Parse(data.c_str()) != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error: Failed to parse XML document." << std::endl;
        return 1;
    }

    const char* name = doc.FirstChildElement("name")->GetText();
    if (name == nullptr) {
        std::cerr << "Error: Name element not found." << std::endl;
        return 1;
    }

    std::cout << name << std::endl;

    return 0;
}
