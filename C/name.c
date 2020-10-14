#include <stdio.h>
int main()
{
    char firstname[20], lastname[20];
    int bir_year;
    printf("Input your firstname: ");
    scanf("%s", firstname);
    printf("Input your lastname: ");
    scanf("%s", lastname);
    printf("Input your year of birth: ");
    scanf("%d", &bir_year);
    printf("%s %s %d\n", firstname, lastname, bir_year);
    return 0;
}
