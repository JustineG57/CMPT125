#include <stdio.h>

// where you include all your functions created outside of main

int main() {
    // Variables: need to mention type, variable name, initialize variable
    int i = 0;
    int n = 0;
    float x;
    int nameofvariable;
    int nameofarray;
    char z;
    
    // In the terminal
    // gcc namefile.c -o namefile


    // Basic functions
    printf("text to print with variable %i", nameofvariable);
    scanf("%i", &nameofvariable);
    // if we use an array
    scanf("%d", nameofarray);
    for ( i = 0 ; i < n ; i++){

    }

    // Always end with a retrun statement
    return 0;

    // Allocate memory
    int *p = NULL;   const int N = 100;
	p = malloc( N * sizeof(int) );
    if (p == NULL){
        printf("Error: allocation failed.\n");
    
      // delete all dynamic variable defined before
      // the allocation failure (clean up) then exit
    } 


}