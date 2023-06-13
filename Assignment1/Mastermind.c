#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main(){

    //Create the 4 arrays
    int* solution;
    int* guess;
    int* match;
    int* dontMatch;
    int* input;
    char nextchar;
    int seed;
    solution = (int*)malloc(6 * sizeof(int*));
    guess = (int*)malloc(6 * sizeof(int));
    match = (int*)malloc(6 * sizeof(int));
    dontMatch = (int*)malloc(6 * sizeof(int));

    //Seed value for the game
    printf("Enter the integer value of the seed for the game:");
    scanf("%i", &seed);

    //Pick 6 random numbers between 0 and 6
    srand(seed);
    for (int i = 0; i < 6; i++){
        do {
            solution[i] = rand() % 7;
        }
        while (solution[i] > 6);
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%i ", solution[i]); 
    }

    //Print rules
    printf("For each turn enter 6 numbers 0 <= num <= 9 \nSpaces or tabs in your response will be ignored.\n");

    //Compare the guess array to the solution array 
    do 
    {
        //Ask for their guess
        int g = 0;
        int c = 0;
        printf("Enter your guess, 6 digits\n");
        nextchar = fgetc(stdin);
        
        //Check the guess input is valid and transfer it to the array
        for (int i = 0; g < 6; i++)
        {
            nextchar = fgetc(stdin);
            if(nextchar >= '0' && nextchar <= '6')
            {
                guess[g] = nextchar - '0'; 
                g += 1;
                c += 1;
            }
            if(nextchar == EOF)
            {
                int missingNum = 6 - g;
                printf("You need to enter %i more digits to complete your guess\n", missingNum);
                c = 0;
            }
            else
            {
                printf("ERROR: A character in your guess was not a digit or a white space\n");
                printf("\n");
                printf("Enter your guess, 6 digits\n");
                c = 0;
                g = 0;
            }
            
        }
    
        //Print a confirmation of the guess that was given 
        printf("Your guess was\n");
        for (int i = 0; i < 6; i++)
        {
            printf("%i ", guess[i]); 
        }
        printf("\n");
        int numMatch = 0;
        int partial = 0;

        //Compare guess and solution
        //Check for correct match
        for (int i = 0; i < 6; i++)
        {
            if (guess[i] == solution[i])
            {
                match[i] = guess[i];
                guess[i] = 7;
                dontMatch[i] = 8;
                numMatch += 1;
            }
            else {
                dontMatch[i] = solution[i];
            }
        }

        for (int i = 0; i < 6; i++)
        {
            printf("%i", dontMatch[i]);
        }
        printf("\n");
        for (int i = 0; i < 6; i++)
        {
            printf("%i", guess[i]); 
        }
        //Check for partial match
        for (int k = 0; k < 6; k++)
        {
            for (int l = 0; l < 6; l++)
            {
                if (guess[k] == dontMatch[l])
                {
                    partial += 1;
                    dontMatch[l] = 8;
                    break;
                }
            }
        }


        //Check if they found the correct answer
        if (numMatch == 6)
        {
            printf("YOU DID IT!!");
            break;
        }
        else
        {
            printf("My response was \n%i matches %i partial matches\n", numMatch, partial);
        }
        
    } while (solution != match);

    free(solution);
    free(guess);
    free(match);
    free(dontMatch);
    
    return;
}
