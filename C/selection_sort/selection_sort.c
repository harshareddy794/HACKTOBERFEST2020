#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// This program implements the selection sort algorithm
// The size of the array is set to 100

	int n; 
	int list[SIZE]; 
	int i, j; 
	int minimum_position; 
	int temp;

	int main()
{
	printf ("How many elements will be in this array? ");
	scanf ("%d", &n);

	printf ("Please type in one integer array element per line:\n");
	for (i = 0; i < n; i++) 
	{
		scanf ("%d", &list[i]);
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
	temp = list[i];
	list[i] = list[minimum_position];
	list[minimum_position] = temp;
	}

	printf ("\n");
	for (i = 0; i < n; i++) 
	{
		printf ("%d\n", list[i]);
	}
	return 0;
}
