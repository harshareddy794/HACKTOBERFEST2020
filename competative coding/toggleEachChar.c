#include<stdio.h>
#include<string.h>
#include<conio.h>
void main(){
    char str[30];
    printf("Enter the string ");
    gets(str);
   // scanf("%s",str);
    
    for(int i=0;str[i];i++){
        if(str[i]>='a' && str[i]<='z')
        str[i]=str[i]-32;
        else if (str[i]>='A' && str[i]<='Z')
        {
                str[i]=str[i]+32;
        }
    }
        
           
 // printf("%s",str);
   puts(str);      
    
}