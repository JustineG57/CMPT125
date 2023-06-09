#include <stdio.h>

void main(){

    // Create the 4 arrays
    int *solution = NULL;
    int *guess = NULL;
    int *match = NULL;
    solution = (int *)malloc(6 * sizeof(int*));
    guess = (int *)malloc(6 * sizeof(int));
    match = (int *)malloc(6 * sizeof(int));

    // Pick 6 random numbers between 0 and 6
    for (int i = 0; i < 6; i++){
        do {
            solution[i] = rand();
        }
        while (solution[i] > 6);
    }

    printf("Enter your guess, 6 digits\n");
    for (int i = 0; i < 6 ; i ++){
        scanf("%i", &guess[i]);
    }
     
}