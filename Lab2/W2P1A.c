#include <stdio.h>

int main(){
    int row = 0; 
    // Ask for the number of rows
    printf("How many rows do you want to print?\n");
    scanf("%i", &row);
    int column = row * 2 + 1;
    int table [column][row];
    int x = 0;
    int n = row;

    if ( 1 < row < 10) {
        // Setup the rows
        for (int i = 0; i < row ; i++) {
            int d = 0;
            
            // Add column of 0
            for (int l = 0; l < n; l++){
                table[l][i] = 0;
                d += 1;
            }
            n -= 1;

            // Add column with numbers
            for (int k = 0; k < row; k++){
                x += 1;
                table[k][i]= x;
                d += 1;
            }

            // Add the last 0
            while (d < column){
                table[d][i]= 0;
                d += 1;
            }
        }
        
        for (int r = 0; r < row; r++){
            for (int c = 0; c < column; c++){
                printf("%2i", table[c][r]);
            }
            printf("\n");
        }
    }    

    else{
        // If number of row incorrect
        printf("ERROR: Value of N supplied is out of range\n");
    }

    return 0;
}