#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f(x) (4*x*x-5*x-10)
#define E 0.00001
int main()
	{
		float x0,x1,x2,ecal,count;
		printf("\n ************Secent Method***************");
		printf("\n Enter initial value :- \n");
		printf("\n x0 = ");
		scanf("%f",&x0);
		printf("\n x1 = ");
		scanf("%f",&x1);
		do{
			x2 = x1-((f(x1)*(x1-x0))/(f(x1)-f(x0)));
			ecal =fabs((x2-x1)/x2);
			x0 = x1;
			x1 = x2;
			printf("\n x0=%f \t x1=%f \t x2=%f \t ecal=%f \n",x0,x1,x2,ecal);
			count += 1;
		}while(E<ecal && count<=12);
		if(count > 12)
			{
				printf("\n Iteration moore than 12, no solution \n");
			}
			printf("\n Root is %f",x2);
			return 0;
	}
