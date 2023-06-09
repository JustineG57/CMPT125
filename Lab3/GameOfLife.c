#include <stdio.h>
#include <ctype.h>

void PrintGen(char **lifeBoard, FILE *OutStream, int numRowsInBoard, int numColsInBoard, int generationNum);
void NextGen (char lifeBoard[][MAX_ARRAY_SIZE], int nuRowsInBoard, int numColsInBoard);

const int MAX_ARRAY_SIZE = 40;
const int MAX_FILENAMELEN = 80;

int main(){
    // Initiate files and variables
    FILE *InStream = NULL;
    FILE *OutStream = NULL;
    int numRowsInBoard = 0;
    int numColsInBoard = 0;
    int generationNum = 0;

    // Request name of the input file
    printf("what is the name of your input file?");
    char filenameIn = "/0";
    scanf("%c", filenameIn);
    
    // Open input file
    InStream = fopen("filenameIn.txt","r");

    // Check file is open
    if (InStream == NULL);
    {
        fprintf( stdout, "ERROR: input file not opened correctly\n");
    }

    // Reading the file
    fscanf(InStream, "%i %i %i", numRowsInBoard, numColsInBoard, generationNum);

    // Check the numbers rows, columns, generations
    if (numRowsInBoard < 1 || numRowsInBoard > MAX_ARRAY_SIZE){
        printf("ERROR: Read an illegal number of rows for the board\n");
        return 1;
    }
    if (numRowsInBoard == NULL){
        printf("ERROR: Cannot read the number of rows\n");
        return 2;
    }
    if (numColsInBoard < 1 || numColsInBoard > MAX_ARRAY_SIZE){
        printf("ERROR: Read an illegal number of columns for the board\n");
        return 3;
    }
    if (numColsInBoard == NULL){
        printf("ERROR: Cannot read the number of columns\n");
        return 4;
    }
    if (!(fscanf(InStream, "%d", &generations))){
        printf("ERROR: There is no value for number of generations in the file\n");
        return 5;
    }
    if (isdigit(generationNum)){
        printf("ERROR: Cannot read the number of generations\n");
        return 6;
    }
    if (generationNum < 0){
        printf("ERROR: Read an illegal number of generations\n");
        return 7;
    }

    // Request name of the output file
    printf("what is the name of your output file?");
    char filenameOut = "/0";
    scanf("%c", filenameOut);

    // Open output file
    OutStream = fopen("filenameOut.txt", "w");




    // Closing Files
    fclose(InStream);
    fclose(OutStream);

    return 0;
}

void PrintGen(char **lifeBoard, FILE *OutStream, int numRowsInBoard, int numColsInBoard, int generationNum){

}


void NextGen (char lifeBoard[][MAX_ARRAY_SIZE], int numRowsInBoard, int numColsInBoard){

    const char organism = 'X';
    int neighborcount;
    char **nextGenBoard = NULL;
    
    nextGenBoard = (char **)malloc(numRowsInBoard * sizeof(char *));
    if (nextGenBoard == NULL){
        print("array of pointer for myLifeBoard could not be allocated\n");
        return 100;
    }

    nextGenBoard[0] = (char *)malloc(numRowsInBoard * numColsInBoard * sizeof(char));
    if (nextGenBoard[0] == NULL){
        printf("array for myLifeBoard could not be allocated\n");
        free(nextGenBoard);
        return 101;
    }

    // Initialize the beginning of each rows
    for (int i = 1; i < numRowsInBoard; i++){
        nextGenBoard[i] = nextGenBoard[0] + i * numColsInBoard;
    }


    free(nextGenBoard);
    free(nextGenBoard[0]);
}