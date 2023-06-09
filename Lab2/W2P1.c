#include <stdio.h>

int main(){
    // Variables
    int N = 0;
    int x = 0;
    int i = 0;
    int l = 0;
    int k = 0;
    
    
    // Ask for the number of rows
    printf("How many rows do you want to print?\n");
    scanf("%i", &N);
    int n = N;
    int y = N * 2;

    if ( 1 < N < 10) {
        // Setup the rows
        for (i = 0; i < N ; i++) {
            int d = 0;
            
            // Print the first 0
            for (l = 0; l < n; l++){
                printf(" 0  ");
                d += 1;
            }
            n -= 1;

            // Print the numbers
            for (k = 0; k < N; k++){
                x += 1;
                printf("%2i  ", x);
                d += 1;
            }

            // Print the last 0
            while (d < y){
                printf(" 0  ");
                d += 1;
            }
            printf (" 0\n");
        }
    }    

    else{
        // If number of row incorrect
        printf("ERROR: Value of N supplied is out of range\n");
    }

    return 0;
}