#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>

int main() {
    xmlDocPtr doc;
    
    // User-supplied XML input (replace this with actual input)
    const char* xmlData = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                          "<!DOCTYPE root [\n"
                          "<!ELEMENT root ANY>\n"
                          "<!ENTITY xxe SYSTEM \"file:///etc/passwd\">\n"
                          "]>\n"
                          "<root>&xxe;</root>";
    
    // Parse the XML document (including external entities)
    doc = xmlReadMemory(xmlData, strlen(xmlData), NULL, NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Error: Failed to parse XML document.\n");
        return 1;
    }
    
    // Process XML data (vulnerable to XXE)
    
    // Free the document
    xmlFreeDoc(doc);
    
    return 0;
}
