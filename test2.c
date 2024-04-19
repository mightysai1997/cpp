#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xmlschemas.h>

int main() {
    xmlDocPtr doc;
    xmlSchemaPtr schema;
    xmlSchemaParserCtxtPtr schemaParserCtxt;
    xmlSchemaValidCtxtPtr schemaValidCtxt;
    xmlNodePtr root;
    
    // Parse XML document
    doc = xmlReadFile("example.xml", NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Error: Failed to parse XML document.\n");
        return 1;
    }
    
    // Create XML schema parser context
    schemaParserCtxt = xmlSchemaNewParserCtxt("example.xsd");
    if (schemaParserCtxt == NULL) {
        fprintf(stderr, "Error: Failed to create XML schema parser context.\n");
        xmlFreeDoc(doc);
        return 1;
    }
    
    // Parse XML schema
    schema = xmlSchemaParse(schemaParserCtxt);
    if (schema == NULL) {
        fprintf(stderr, "Error: Failed to parse XML schema.\n");
        xmlSchemaFreeParserCtxt(schemaParserCtxt);
        xmlFreeDoc(doc);
        return 1;
    }
    
    // Create XML schema validation context
    schemaValidCtxt = xmlSchemaNewValidCtxt(schema);
    if (schemaValidCtxt == NULL) {
        fprintf(stderr, "Error: Failed to create XML schema validation context.\n");
        xmlSchemaFree(schema);
        xmlSchemaFreeParserCtxt(schemaParserCtxt);
        xmlFreeDoc(doc);
        return 1;
    }
    
    // Validate XML document against schema
    if (xmlSchemaValidateDoc(schemaValidCtxt, doc) != 0) {
        fprintf(stderr, "Error: XML document failed schema validation.\n");
        xmlSchemaFreeValidCtxt(schemaValidCtxt);
        xmlSchemaFree(schema);
        xmlSchemaFreeParserCtxt(schemaParserCtxt);
        xmlFreeDoc(doc);
        return 1;
    }
    
    // Get the root element
    root = xmlDocGetRootElement(doc);
    if (root == NULL) {
        fprintf(stderr, "Error: Empty document.\n");
        xmlSchemaFreeValidCtxt(schemaValidCtxt);
        xmlSchemaFree(schema);
        xmlSchemaFreeParserCtxt(schemaParserCtxt);
        xmlFreeDoc(doc);
        return 1;
    }
    
    // Process XML data
    
    // Free resources
    xmlSchemaFreeValidCtxt(schemaValidCtxt);
    xmlSchemaFree(schema);
    xmlSchemaFreeParserCtxt(schemaParserCtxt);
    xmlFreeDoc(doc);
    
    return 0;
}
