#include <stdio.h>
#include <stdlib.h>

//My functions
void FillZero(int **my2DArray, int M, int N);
void CopyArray(int **my2DArray, int**myNextGenArray, int M, int N);
void NextGen(int **board, int M, int N); 

int main () {

    //Initiate files and variables
    FILE *OutStream = NULL;
    FILE *InStream = NULL;
    int numRows = 0;
    int numCols = 0;
    int numGeneration = 0;
    int numIncrement = 0;

    //Request name of the input file
    printf("Enter the name of the input file:");
    char inputFile;
    scanf("%c", &inputFile);

    //Open input file
    InStream = fopen("inputFile.txt","r");

    //Check file is open
    if (InStream == NULL);
    {
        fprintf(stdout, "ERROR: Input file not opened correctly.");
        fclose(InStream);
        return 1;
    }

    //Request name of the output file
    printf("Enter the name of the output file:");
    char outputFile;
    scanf("%c", &outputFile);

    //Open output file
    OutStream = fopen("outputFile.txt","r");

    //Check file is open
    if (OutStream == NULL);
    {
        fprintf(stdout, "ERROR: Output file not opened correctly.");
        fclose(OutStream);
        fclose(InStream);
        return 2;
    }

    //Ask the user for the number of rows
    printf("Enter the number of rows in the board (0<number<40)\n");
    scanf("%i", &numRows);

    //Check the number of rows is an integer and is within range
    while (numRows <= 0 || numRows >= 40){
        printf("ERROR: Read an illegal number of rows for board\n");
        printf("TRY AGAIN, 0 < number of rows < 40: ");
        scanf("%i", &numRows);
    }
    if (isdigit(numRows)){
        printf("ERROR: The value of numRows is not an integer\n");
        fclose(OutStream);
        fclose(InStream);
        return 1;
    }
    
    //Ask the user for the number of columns
    printf("Enter the number of columns in the board (0<number<80)\n");
    scanf("%i", &numCols);

    //Check the number of columns is an integer and is within range
    while (numCols <= 0 || numCols >= 80){
        printf("ERROR: Read an illegal number of columns for board\n");
        printf("TRY AGAIN, 0 < number of columns < 80");
        scanf("%i", &numCols);
    }
    if (isdigit(numCols)){
        printf("ERROR: The value of numCols is not an integer\n");
        fclose(OutStream);
        fclose(InStream);
        return 1;
    }

    //Read the number of generations and increment from the input file
    fscanf(InStream, "%i %i", &numGeneration, &numIncrement);

    //Check number of generation is there, is an integer, is within range
    if (numGeneration == NULL){
        printf("ERROR: Could not read the number of generations\n");
        fclose(OutStream);
        fclose(InStream);
        return 1;
    }
    if (isdigit(numGeneration)){
        printf("ERROR: number of generations is not an integer\n");
        fclose(OutStream);
        fclose(InStream);
        return 1;
    }
    if (numGeneration <= 0){
        printf("ERROR: Read an illegal number of generations\n");
        fclose(OutStream);
        fclose(InStream);
        return 1;
    }

    //Check number of increment is there, is an integer, is within range
    if (numIncrement == NULL){
        printf("ERROR: Could not read the generation increment\n");
        fclose(OutStream);
        fclose(InStream);
        return 1;
    }
    if (isdigit(numIncrement)){
        printf("ERROR: generation increment is not an integer\n");
        fclose(OutStream);
        fclose(InStream);
        return 1;
    }
    if (numIncrement <= 0){
        printf("ERROR: Read an illegal generation increment\n");
        fclose(OutStream);
        fclose(InStream);
        return 1;
    }

    //Dynamically allocate a 2-D integer array to represent the board.
    int **board;
    board = (int **)malloc(numRows * sizeof(int*));
    
	if (board == NULL){
		printf("array of pointer for board could not be allocated\n");
		fclose(InStream);
		fclose(OutStream);
		exit(1);
	}
	
    board[0] = (int *)malloc(numRows*numCols * sizeof(int));
	if (board[0] == NULL){
		printf("array for board could not be allocated\n");
		fclose(InStream);
		fclose(OutStream);
		exit(1);
	}
	for (int i = 1; i < numRows; i++)
	{
		board[i] = board[0] + i * numCols;
	}

    //Fill the board with 0
    FillZero(board, numRows, numCols);

    //Initialize the first 1
    board[1][3] = 1;

    //Calculate the next generation
    NextGen(board, numRows, numCols);

    //Free memory space
    free(board[0]);
    free(board);

    //Close files
    fclose(InStream);
    fclose(OutStream);

    return 0;
}

void FillZero( int **my2DArray, int M, int N){
    for (int i = 0; i < M; i++){
        for (int j = 0; i < N; j++){
            my2DArray[i][j] = 0;
        }
    }
}

void CopyArray(int **my2DArray, int **myNextGenArray, int M, int N){
    //Need to use pointer arithmetic
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            my2DArray[i][j] == myNextGenArray[i][j];
        }
    }
}

void NextGen(int ** board, int M, int N){

   //Dynamically allocate a 2-D integer array to represent the next gen board. Initialize all elements to 0
    int **nextGenBoard;
    nextGenBoard = (int **)malloc(M * sizeof(int*));
    
	if (nextGenBoard == NULL){
		printf("array of pointer for board could not be allocated\n");
		exit(1);
	}
	
    nextGenBoard[0] = (int *)malloc(M*N* sizeof(int));
	if (nextGenBoard[0] == NULL){
		printf("array for board could not be allocated\n");
		exit(1);
	}
	for (int i = 1; i < M; i++)
	{
		nextGenBoard[i] = nextGenBoard[0] + i * N;
	}

    FillZero(nextGenBoard, M, N);

    for (int k = 0; k < M; k++){
        for (int j = 0; j < N; j++){
            if (j == 0 || k == 0 || j == k == 0){
                nextGenBoard[k][j] = 0;
            }
            else{
                nextGenBoard[k][j] = ( board[k][j] + board[k-1][j] + board[k][j-1] ) % 2;
            }
        }
    }

    CopyArray(board, nextGenBoard, M, N);

    free(nextGenBoard[0]);
    free(nextGenBoard);
}