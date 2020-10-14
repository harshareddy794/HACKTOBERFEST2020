#include<stdio.h>
int main(){
 int first,second,third;
 printf("enter 3 digit number\n");
 scanf("%1d%1d%1d",&first,&second,&third);
 switch(first%10)
 {
   case 1: printf(" One hundred");
   break;
  case 2: printf(" Two hundred");
  break;
  case 3: printf(" Three hundred");
  break;
  case 4: printf(" Four hundred");
  break;
  case 5: printf(" Five hundred");
  break;
  case 6: printf(" Six hundred");
  break;
  case 7: printf(" Seven hundred");
  break;
  case 8: printf(" Eight hundred");
  break;
  case 9: printf(" Nine hundred");
  break;
 }
  switch(second%10){
  case 0:break;

  case 1: switch(third%10){
  	printf("and");
  case 0: printf(" ten");break;
  case 1: printf(" eleven");break;
  case 2: printf(" twelve");
   break;
  case 3: printf("thirteen");
  break;
  case 4: printf(" fourteen");
  break;
  case 5: printf(" fifteen");
  break;
  case 6: printf(" sixteen");
  break;
  case 7: printf(" seventeen");
  break;
  case 8: printf(" eighteen");
  break;
  case 9: printf(" nineteen");
  break;

  }
  return 0;

  break;
  case 2: printf(" tewnty");
  break;
  case 3: printf(" thirty");
  break;
  case 4: printf(" fourty");
  break;
  case 5: printf(" fifty");
  break;
  case 6: printf(" sixty");
  break;
  case 7: printf(" seventy");
  break;
  case 8: printf(" eighty");
  break;
  case 9: printf(" ninety");
  break;
 }
 switch(third%10){
  case 0:break;
  printf("and");
  case 1: printf(" one");
  break;
  case 2: printf(" two");
  break;
  case 3: printf(" three");
  break;
  case 4: printf(" four");
  break;
  case 5: printf(" five");
  break;
  case 6: printf(" six");
  break;
  case 7: printf(" seven");
  break;
  case 8: printf(" eight");
  break;
  case 9: printf(" nine");
  break;
 }
}
