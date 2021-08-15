#include <stdio.h>
void main()
{
    int n;
    printf("Enter the decimal number\n");
    scanf("%d", &n);
    int i = 0, arr[200], r = 0, m = 0, j = 0;
    m = n;
    if (m == 0)
    {
        printf("the binary number is:\n");
        printf("%d", m);
    }
    else
    {
        while (m > 0)
        {
            r = m % 2;
            arr[i] = r;
            m = m / 2;
            i++;
        }
        printf("\nThe binary number is:\n");
        for (j = i - 1; j >= 0; j--)
            printf("%d ", arr[j]);
    }
}
/* SAMPLE OUTPUT
Enter the decimal number
25

The binary number is:
1 1 0 0 1*/