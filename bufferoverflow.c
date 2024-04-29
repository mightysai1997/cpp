/*
Sample code for vulnerable type: Buffer Copy without Checking Size of Input ('Classic Buffer Overflow')
CWE : CWE-120
Description : The input read from gets without verifying the size of the input, data is printed out to buffer is less than the size of the output buffer, leading to a buffer overflow.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE (1024)

int main() {
    char buffer[BUFFERSIZE];    
    gets(buffer); //source
    printf("Input read: %s", buffer); //sink
    perform_string_operation(buffer); 
    return 0;
}
