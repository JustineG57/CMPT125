#include <stdio.h>
#include <math.h>

int main() {
    // Variables
    int i;
    float x = 0;
    float xcube = 0;
    float xsquare = 0;
    float n = 0;
    int row = 0;
    
    // Ask for the value of x
    printf("Please enter the value of x: ");
    scanf("%f", &x);
    
    // Calculate the square and cube of x
    xsquare = x*x;
    xcube = x*x*x;

    // Ask for the value of the increment n
    printf("Please enter the value of the increment between X on successive rows: ");
    scanf("%f", &n);

    // Ask for the number of rows
    printf("Please the number of rows you want in the table: ");
    scanf("%i", &row);

    /*Print the headers for the table*/
	printf("%16s", "XValue");
	printf("%16s", "Xsquared");
	printf("%16s\n", "Xcubed");

    // Print the table
    for (i = 0; i < row; i++) {
        
        xsquare = x*x;
        xcube = x*x*x;

        printf("%+16.4f %16.3f %16.5e\n", x, xsquare, xcube);
        
        x = x + n;
    }
    
    return 0;
}