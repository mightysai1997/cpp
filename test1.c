#include <stdio.h>
#include <libxml/parser.h>

int main() {
    xmlDocPtr doc;
    xmlNodePtr root;
    
    // Parse XML document while disabling external entity resolution
    doc = xmlReadFile("example.xml", NULL, XML_PARSE_NOENT);
    if (doc == NULL) {
        fprintf(stderr, "Error: Failed to parse XML document.\n");
        return 1;
    }
    
    // Get the root element
    root = xmlDocGetRootElement(doc);
    if (root == NULL) {
        fprintf(stderr, "Error: Empty document.\n");
        xmlFreeDoc(doc);
        return 1;
    }
    
    // Process XML data
    
    // Free the document
    xmlFreeDoc(doc);
    
    return 0;
}
