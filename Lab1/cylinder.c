#include <stdio.h>

// This program calculates the volume of a cylinder
// The radius and length of the cylinder are provided by the user of the program
// Author:  Janice Regan
// Date:  May 2023

int main (void)
{
	const double PI = 3.14159;
	double radius = 0.0;
	double length = 0.0;
	double volume = 0.0;
	
	printf( "Please enter a value for the radius of the cylinder: ");
	scanf("%lf", &radius);

	printf( "Please enter a value for the length of the cylinder: ");
	scanf("%lf", &length);
	
	volume = PI * radius * radius * length;
	printf("The volume of the cylinder with radius %-.3lf ", radius);
    printf("and length %-.3lf\nis %-.3lf\n", length, volume);       

	return 0;
}