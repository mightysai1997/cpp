/*
Sample code for vulnerable type: Double free
CWE : CWE-415
Description : The below-provided code, Potential double call to free. ptr may have already been freed.
*/

#include <stdlib.h>
#define SIZE 16
int main(){
    char* ptr = (char*)malloc (SIZE);//source
    if (1) {
        free(ptr);
    }
    free(ptr);//sink
    return 0;
}
