#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

void parse_xml(const char* filename) {
    xmlDocPtr doc;
    xmlNodePtr root;

    // Parse the XML file
    doc = xmlReadFile(filename, NULL, 0);
    if (doc == NULL) {
        printf("Error: Unable to parse XML file.\n");
        return;
    }

    // Get the root element
    root = xmlDocGetRootElement(doc);
    if (root == NULL) {
        printf("Error: Empty XML file.\n");
        xmlFreeDoc(doc);
        return;
    }

    // Traverse the XML tree and process nodes (not shown in this example)

    // Free the XML document
    xmlFreeDoc(doc);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    // Vulnerability: Directly passing user input to parse_xml function
    parse_xml(argv[1]);

    return 0;
}
