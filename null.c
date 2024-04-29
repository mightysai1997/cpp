/*
Sample code for vulnerable type: Dereference of a NULL Pointer
CWE : CWE-476
Description : A pointer is assigned to NULL then used. NULL pointer use can lead to program crashes.
*/

#define NULL 0
int main(){
   int *p=NULL; //source
   if (*p){ //sink

   }
   return 0;
}
