#include<stdio.h>
#include<string.h>

void remove_space(char str[]){
    int i,l=0;
   // char j[100];
    for(i=0;str[i]!='\0';++i)
    {
        if((str[i]>='a'&& str[i]<='z')||(str[i]=='A'&& str[i]=='Z')){
        
        str[l++]=str[i];
    
        }
        else{
        ++i;
        }
   // l++;
    }
    str[l]='\0';
    puts(str);
}

int main()
{
    
    char str[100];
    printf("Enter all the char : ");
    gets(str);
    remove_space(str);
   // puts(str);
    return 0;
}
