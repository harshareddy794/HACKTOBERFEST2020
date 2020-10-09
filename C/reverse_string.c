#include <stdio.h>

int main()
{
    char str[100];
    char rev[100];
    char *sptr = str;  //base address of string
    char *rptr = rev;  //base address of reverse

    int i = -1;

    printf("Enter a String: \n");
    scanf("%s", str);

    // store the ending address of str in sptr
    while (*sptr)
    {
        sptr++;
        i++;
    }

    // store the string str in rev in reverse order
    while (i >= 0)
    {
        sptr--;
        *rptr = *sptr;
        rptr++;
        i--;
    }

    *rptr = '\0';
    rptr = rev; // restoring the base address of the reverse string

    // storing the reverse string in the original string
    while (*rptr)
    {
        *sptr = *rptr;
        sptr++;
        rptr++;
    }

    // priting the reverse string
    printf("Reverse of the string is :\n%s", str);
    return 0;
}