#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
  char str[] = "string-what-you-want";
  char *token;
  printf("The String is : \n%s",str);
  token = strtok(str,"-");
  
  while(token != NULL){
    printf("Token : %s\n",token);
    token = strtok(NULL,"-");
  }
  return 0;
  

}


//  OUTPUT : 
//  string-what-you-want
//  string
//  what
//  you
//  want
