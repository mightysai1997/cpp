#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>

int main() {
    xmlDocPtr doc;
    
    // User-supplied XML input (replace this with actual input)
    const char* xmlData = "<root>Hello, world!</root>";
    
    // Check for external entity references in the input
    if (strstr(xmlData, "<!ENTITY") != NULL) {
        fprintf(stderr, "Error: XML input contains external entity references.\n");
        return 1;
    }
    
    // Parse sanitized XML document
    doc = xmlReadMemory(xmlData, strlen(xmlData), NULL, NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Error: Failed to parse XML document.\n");
        return 1;
    }
    
    // Process XML data
    
    // Free the document
    xmlFreeDoc(doc);
    
    return 0;
}
