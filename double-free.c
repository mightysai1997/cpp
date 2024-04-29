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
