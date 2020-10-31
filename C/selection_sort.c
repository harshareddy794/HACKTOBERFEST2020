#include <stdio.h>
#include <stdlib.h>
#define SIZE 100		//pre-defining size to be of 100

// This program implements the selection sort algorithm
// The size of the array is set to 100

	int n; 		//variable that is used to input the number of elements the user need to enter
	int list[SIZE]; //creating a variable named list with pre-defined size 100 that would be our array to store the input elements
	int i, j; 	
	int minimum_position; 
	int temp;	//temporary variable that would help us in swapping elements

	int main()
{
	printf ("How many elements will be in this array? ");
	scanf ("%d", &n);

	printf ("Please type in one integer array element per line:\n");
	for (i = 0; i < n; i++) 
	{
		scanf ("%d", &list[i]);		//this statement helps to take in input from the user in one line per element
	}

	for (i = 0; i < n - 1; i++) 
	{
	minimum_position = i;
		for (j = i + 1; j < n; j++) 
		{
			if (list[j] < list[min_pos]) 
			{
				min_pos = j;
			}
		}
	temp = list[i];			//we swap the elements using temp variable---Step1
	list[i] = list[minimum_position];	//Step2
	list[minimum_position] = temp;		//Final Step of swapping
	}

	printf ("\n");				//this provides a one-line gap between the input and output while being displayed on the compiler/ide output
	for (i = 0; i < n; i++) 
	{
		printf ("%d\n", list[i]);
	}
	return 0;
}
