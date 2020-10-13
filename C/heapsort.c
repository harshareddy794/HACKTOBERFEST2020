#include <stdio.h>
void main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n); //user inputs the number of elements to be sorted
    int arr[1000], i, j, c, p, temp, ch;
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); //user inputs the elements
    }
    for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            p = (c - 1) / 2;
            if (arr[p] < arr[c]) //elemnents swapped
            {
                temp = arr[p];
                arr[p] = arr[c];
                arr[c] = temp;
            }
            c = p;
        } while (c != 0);
    }
    for (j = n - 1; j >= 0; j--) //main program
    {
        temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;
        p = 0;
        do
        {
            c = 2 * p + 1;
            if ((arr[c] < arr[c + 1]) && (c < j - 1))
                c++;
            if ((arr[p] < arr[c]) && (c < j))
            {
                temp = arr[p];
                arr[p] = arr[c];
                arr[c] = temp;
            }
            p = c;
        } while (c < j);
    }
    printf("\nPress 1 for min heap\nPress 2 for max heap\n\nEnter your choice\n");
    scanf("%d", &ch); //user enters his choice of printing the heap
    switch (ch)
    {
    case 1:
        printf("\nThe elements sorted according to min heap are - \n");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        break;
    case 2:
        printf("\nThe elements sorted according to max heap are - \n");
        for (i = n - 1; i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
        break;
    default:
        printf("Wrong choice\n");
    }
}
/* SAMPLE OUTPUT
Enter the number of elements
4
Enter the elements
6 -4 0 4

Press 1 for min heap
Press 2 for max heap

Enter your choice
2

The elements sorted according to max heap are -
6 4 0 -4*/