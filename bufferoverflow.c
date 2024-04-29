/*
Sample code for vulnerable type: Buffer Copy without Checking Size of Input ('Classic Buffer Overflow')
CWE : CWE-120
Description : The product copies an input buffer to an output buffer without verifying that the size of the input buffer is less than the size of the output buffer, leading to a buffer overflow.
*/

#include <stdio.h>

// Source function: Vulnerability - Conversion of integer to char without bounds checking
char convertToInt(int opt) {
    return (char)opt; // Source of vulnerability
}

// Sink function: No buffer overflow vulnerability here, just demonstration of using the converted char
void processChar(char opt_char) {
    printf("Processed character: %c\n", opt_char);
}

int main() {
    int opt = 300; // Assume opt is received from an untrusted source

    // Source function call
    char opt_char = convertToInt(opt);

    // Sink function call
    processChar(opt_char);

    return 0;
}
