// Answer from the teacher

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


const int MAX_ARRAY_SIZE = 40;
const int MAX_FILENAMELEN = 40;

int  NextGen(char **lifeBoard, int numRowsInBoard, int numColsInBoard);
void  PrintGen(char **lifeBoard, FILE *OutStream,
    int numRowsInBoard, int numColsInBoard, int generationNum);

int main()
{
	/*This program implements the game of life
	  Initial data is read from a file
	  First row of data is
	  number of rows in gameBoard,
	  number of columns in gameBoard,
	  number of generations to calculate,
	  increment n, print every nth generation to the screen
	  increment m, print every mth generation to the file
	  The remaining rows in the input file are the initial
	  configuration of the gameboard.

	  Author Janice Regan 2023; 
	 */

	 //Define the streams for input and for output
	FILE* inStream = NULL;
	FILE* outStream = NULL;
	char** myLifeBoard;


	int checkflag;
	int trialCount = 0;
	int generations = 0;
	int numRows = 0;
	int numCols = 0;

	char inputFileName[80];
	char outputFileName[80];

	/*Read the filename for the input file
	  Open the file and check that it opened correctly
	  Retry up to 4 times */
	trialCount = 0;
	do
	{
		printf("Enter the name of the input file: ");
		scanf("%s", inputFileName);
		inStream = fopen(inputFileName, "r");
		if (inStream == NULL)
		{
			printf("ERROR: input file not opened correctly\n");
			trialCount++;
			if (trialCount >= 4)
			{
				printf("ERROR: to many incorrect filenames \n");
				return(1);
			}
		}
		else
		{
			break;
		}
	} while (trialCount < 4);


	/* Read the dimensions of the myLifeBoard,
	   the number of generations to calculate and
	   the initial configuration of the myLifeBoard from
	   the input file, check validity of data */
	if (!(fscanf(inStream, "%d", &numRows)))
	{
			printf("ERROR: Cannot read number of rows\n");
			return 2;
	}
	if (numRows < 1 || numRows > MAX_ARRAY_SIZE)
	{
		printf("ERROR: Read an illegal number of rows for the board\n");
		return 3;
	}
	if (!(fscanf(inStream, "%d", &numCols)))
	{
		printf("ERROR: Cannot read number of columns\n");
		return 4;
	}
	if (numCols < 1 || numCols > MAX_ARRAY_SIZE)
	{
		printf("ERROR: Read an illegal number of columns for the board\n");
		return 5;
	}
	if (!(fscanf(inStream, "%d", &generations)))
	{
		if (feof(inStream))
		{
			printf("ERROR: There is no value for number of generations in the file\n");
			return 6;
		}
		else
		{
			printf("ERROR: Cannot read the number of generations\n");
			return 7;
		}

	}
	if (generations < 0)
	{
		printf("ERROR: Read an illegal nummber of generations\n");
		return 8;
	}

	myLifeBoard = (char**)malloc(numRows * sizeof(char*));
	if (myLifeBoard == NULL)
	{
		printf("array of pointer for myLifeBoard could not be allocated\n");
		fclose(inStream);
		fclose(outStream);
		exit(1);
	}
	myLifeBoard[0] = (char *)malloc(numRows*numCols * sizeof(char));
	if (myLifeBoard[0] == NULL)
	{
		printf("array for myLifeBoard could not be allocated\n");
		fclose(inStream);
		fclose(outStream);
		exit(1);
	}
	for (int i = 1; i < numRows; i++)
	{
		myLifeBoard[i] = myLifeBoard[0] + i * numCols;
	}


    /* Read the initial game board from the input file */
	char mytemp = ' ';
	while (mytemp == ' ' || mytemp == '\n' || mytemp == '\t')
	{
		mytemp = getc(inStream);
	}
	ungetc(mytemp, inStream);
    for (int i = 0; i < numRows; i++) 
    {
        /* The end line  character is read 
           Then the MAX_ARRAY_SIZE characters in the row are read */
        for (int j = 0; j < numCols; j++)
        {
            {
                if (!(fscanf(inStream, "%c ", &myLifeBoard[i][j])))
                {
                    printf("ERROR: Not enough data in the input file\n");
                    return 9;
                }
            }

            if (myLifeBoard[i][j] != 'X' && myLifeBoard[i][j] != '.')
            {
				printf("ERROR: Input data for initial board is incorrect\n");
				printf("Location (%d, %d), is not valid", i, j);
                return 10;
            }

        }
    }


    /* Test to assure that the input array does not include organisms */
    /* along its boundaries. */
    /* If the initial myLifeBoard is OK then print it to the screen and */
    /* to the output file using the PrintGen function */
    checkflag = 0;
    for (int i = 0; i < numRows; i++)
    {
        if (myLifeBoard[i][0] == 'X') checkflag++;
        if (myLifeBoard[i][numCols - 1] == 'X') checkflag++;
    }
    for (int i = 0; i < numCols; i++)
    {
        if (myLifeBoard[numRows - 1][i] == 'X') checkflag++;
        if (myLifeBoard[0][i] == 'X') checkflag++;
    }
    if (checkflag > 0)
    {
        printf( "ERROR: organisms are present in the border of the board please correct your input file\n");
        return  11;
    }
 
    fclose( inStream );


    //Read the filenames for the output file
    //in which game boards for each generation
    //will be stored. 
    //Open the output file and
    //check that it has been opened correctly
    trialCount = 0;
    do
    {
        printf( "Enter the name of the output file: ");
        scanf("%s", outputFileName);
        outStream = fopen(outputFileName, "w");
        if (outStream == NULL)
        {
            printf("ERROR: output file not opened correctly\n)");
            
            trialCount++;
            if (trialCount >= 4)
            {
                printf("ERROR: to many incorrect filenames\n");
                return 12;
            }
        }
        else
        {
            break;
        }
    } while (trialCount < 4);


    // print the original board configuration to the screen
    // print the original board configuration to the file
    PrintGen(myLifeBoard, outStream, numRows, numCols, 0);
    PrintGen(myLifeBoard, stdout, numRows, numCols, 0);

    // loop over the indicated number of generations 
    // calculate and print desired outputs for each generation
    for (int i = 1; i <= generations; i++)
    {
        // print the game board 
        NextGen(myLifeBoard, numRows, numCols);
        PrintGen(myLifeBoard, outStream, numRows, numCols, i);
        if (i == 1 || i == generations)
        {
            PrintGen(myLifeBoard, stdout, numRows, numCols, i);
        }
    }
    fclose(outStream);
	free(myLifeBoard[0]);
	free(myLifeBoard);

    return 0;
}


void  PrintGen(char **lifeBoard, FILE * outStream,
    int numRowsInBoard, int numColsInBoard, int generationNum)
{
    /*print a message indicating the generation number
      print the lifeBoard for that generation
      Author Janice Regan; November 3, 2007  & */

    if (generationNum < 0)
    {
        fprintf(outStream, "ERROR: negative generation number: not printing\n");
    }
    else if (generationNum == 0)
    {
        fprintf(outStream, "\n\n\nLIFE initial game board\n");
    }
    else
    {
        fprintf(outStream, "LIFE gameboard: generation %d\n", generationNum );
    }

    for (int i = 0; i < numRowsInBoard; i++)
	{
        for (int j = 0; j < numColsInBoard; j++)
        {
            fprintf(outStream, "%c ", lifeBoard[i][j]);
        }
        fprintf(outStream, "\n");
    }
    fprintf(outStream, "\n\n\n");
	return;
}



int  NextGen(char **lifeBoard, int numRowsInBoard, int numColsInBoard)
{
    /*This program takes the lifeboard and calculates
      another board in which it places the next generation
      The new generation is then copied back into lifeboard
      to be returned to the calling progran
      Author Janice Regan; 2023
	*/

    const char organism = 'X';      // to compare for organisms
    int neighborcount;              // used to count the neighbors 
	char **nextGenBoard = NULL;

	nextGenBoard = (char **)malloc(numRowsInBoard * sizeof(char*));
	if (nextGenBoard == NULL)
	{
		printf("array of pointer for myLifeBoard could not be allocated\n");
		return 100;
	}
	nextGenBoard[0] = (char *)malloc(numRowsInBoard*numColsInBoard * sizeof(char));
	if (nextGenBoard[0] == NULL)
	{
		printf("array for myLifeBoard could not be allocated\n");
		free(nextGenBoard);
		return 101;
	}
	for (int i = 1; i < numRowsInBoard; i++)\
	{
		nextGenBoard[i] = nextGenBoard[0] + i * numColsInBoard;
	}


    /* step over each element except edge elements  
       This function assumes that the edge elements are not organisms 
       It is the responsibility of the user to supply input that does 
       not include organisms on its boundaries */  
    for (int indexrow = 1; indexrow <= numRowsInBoard - 2; indexrow++)
    {
        for (int indexcol = 1; indexcol <= numColsInBoard - 2; indexcol++)
        {
            neighborcount = 0;
            /* determine now many neighbors this element has 
               individually check each adjacent element to see 
               if it is an organism 
               increment the counter if it is  */
            if (lifeBoard[indexrow - 1][indexcol - 1] == organism)
            {
                neighborcount++;
            }
            if (lifeBoard[indexrow][indexcol - 1] == organism)
            {
                neighborcount++;
            }
            if (lifeBoard[indexrow + 1][indexcol - 1] == organism)
            {
                neighborcount++;
            }
            if (lifeBoard[indexrow - 1][indexcol] == organism)
            {
                neighborcount++;
            }
            if (lifeBoard[indexrow + 1][indexcol] == organism)
            {
                neighborcount++;
            }
            if (lifeBoard[indexrow - 1][indexcol + 1] == organism)
            {
                neighborcount++;
            }
            if (lifeBoard[indexrow][indexcol + 1] == organism)
            {
                neighborcount++;
            }
            if (lifeBoard[indexrow + 1][indexcol + 1] == organism)
            {
                neighborcount++;
            }

            /* apply the rules to determine if this location 
               should hold an organism in the next generation */ 

            if (neighborcount == 3)
            {
                nextGenBoard[indexrow][indexcol] = organism;
            }
            else if (neighborcount == 2)
            {
                nextGenBoard[indexrow][indexcol] =
                    lifeBoard[indexrow][indexcol];
            }
            else
            {
                nextGenBoard[indexrow][indexcol] = '.';
            }
        }
    }



    /* copy the new generation array into the lifeBoard array 
       note that the elements on the edges of the arrays are  
       not being copied.  The edge elements are not fertile   
       they can never contain organisms, so they do not need  
       to be updated */
    for (int indexrow = 1; indexrow <= numRowsInBoard - 2; indexrow++)
    {
        for (int indexcol = 1; indexcol <= numColsInBoard - 2; indexcol++)
        {
            lifeBoard[indexrow][indexcol] =
                nextGenBoard[indexrow][indexcol];
        }
    }
	free(nextGenBoard[0]);
	free(nextGenBoard);
	return 0;
}