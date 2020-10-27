#include<stdio.h>    
#include<stdlib.h>  
int main(){  
  int i,j,k,l,n;    
system("cls");  
printf("enter the range=");    
scanf("%d",&n);    
for(i=1;i<=n;i++)    
{    
 for(j=1;j<=n-i;j++)    
  {    
    printf(" ");    
  }    
 for(k=1;k<=i;k++)    
  {    
   printf("%d",k);    
  }    
 for(l=i-1;l>=1;l--)    
  {    
   printf("%d",l);    
  }    
  printf("\n");    
 }    
 return 0;  
}  

//Like alphabet triangle, we can write the c program to print the number triangle. The number triangle can be printed in different ways.

//Let's see the c example to print number triangle.

//enter the range=10
//         1
//        121
//       12321
//      1234321
//     123454321
//    12345654321
//   1234567654321
//  123456787654321
// 12345678987654321
//12345678910987654321
