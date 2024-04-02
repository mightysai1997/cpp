#include <iostream>
#include <cstring>
#include <cstdlib>

// Pattern 1: Returning the address of a local variable directly
char* getName1() {
    char name[100];
    std::strcpy(name, "John Doe");
    return name; // Vulnerability: Returning the address of a local variable directly
}

// Pattern 2: Returning the address of a dynamically allocated variable directly
char* getName2() {
    char* name = new char[100]; // Dynamically allocating memory
    std::strcpy(name, "Jane Smith");
    return name; // Vulnerability: Returning the address of dynamically allocated memory directly
}

int main() {
    char last_name[20];

    // Pattern 1: Using std::strcpy without checking bounds
    std::strcpy(last_name, getName1()); // Sink: Copying data from the returned address to 'last_name'
    std::cout << "Pattern 1 - Last name: " << last_name << std::endl;

    // Pattern 2: Using std::strcpy with dynamically allocated memory
    char* ptr = getName2(); // Assigning the returned address to a pointer
    std::strcpy(last_name, ptr); // Sink: Copying data from the returned address to 'last_name'
    std::cout << "Pattern 2 - Last name: " << last_name << std::endl;

    // Freeing dynamically allocated memory
    delete[] ptr;

    return 0;
}
