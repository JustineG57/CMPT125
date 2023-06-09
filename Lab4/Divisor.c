#include <stdio.h>

int main(){

    // Variables
    int rangeMin = 0;
    int rangeMax = 0;
    int divisor = 0;
    int result = 0;
    int sumDiv = 0;
    int sumNonDiv = 0;

    // Ask for the range of integers
    printf("Enter the smallest integer to consider as part of the sum:");
    scanf("%i", &rangeMin);
    printf("Enter the largest integer to consider as part of the sum:");
    scanf("%i", &rangeMax);
    printf("Enter the divisor of interest:");
    scanf("%i", &divisor);

    //Errors
    if (divisor == 0){
        printf("Divisor is 0, Cannot divide by 0: ERROR\n");
        return 1;
    }
    if (rangeMax < rangeMin){
        printf("No integer larger than %i and smaller than %i\n", rangeMin, rangeMax);
        return 2;
    }
    if (divisor > rangeMax){
        printf("Divisor is larger than the largest integer, no integers are exactly divisible by %i\n", divisor);
    }
    else{
        printf("The numbers between %i and %i that are divisible by %i are:\n", rangeMin, rangeMax, divisor);
    }
    
    // Find the integers that can be divided by divisor with no remainder
    for ( int i = rangeMin; i <= rangeMax; i++){
        if (i % divisor == 0){
            printf("%i, ", i);
            sumDiv = sumDiv + i;
        }
        else{
            sumNonDiv = sumNonDiv +i;
        }
    }
    printf("\n");

    //Print the sums
    if (divisor > rangeMax){
        printf("The sum of all integers between %i and %i that are not divisible by %i is %i. \n", rangeMin, rangeMax, divisor, sumNonDiv);
    }
    else{
        printf("The sum of all integers between %i and %i that are divisible by %i is %i. \n", rangeMin, rangeMax, divisor, sumDiv);
        printf("The sum of all integers between %i and %i that are not divisible by %i is %i. \n", rangeMin, rangeMax, divisor, sumNonDiv);
    }
    

    return 0;
}