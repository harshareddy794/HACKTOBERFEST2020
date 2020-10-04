#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f(x) (5*x*x*x*x*x-3*x*x-100)
#define g(x) (25*x*x*x*x-6*x)
#define E 0.00001
int main()
	{
		float ecal,xi,x0,count;
		printf("\n************************Newton Raphson Method**********************************\n");
		printf("\n Enter initial value x0 = ");
		scanf("%f",&x0);
		if(g(x0)==0)
			{
				printf("\n Sorry the first derivative is zero, enter another initial value. \n");
			}
		else
			{
			do{
					xi = x0 -(f(x0)/g(x0));
					ecal = fabs((xi-x0)/xi);
				x0 = xi;
				printf("\n x0=%f \t f(x0)=%f \t g(x0)=%f \t xi=%f \t ecal=%f \n",x0,f(x0),g(x0),xi,ecal);
				count += 1;
			}while(E<ecal && count<=12);
			if(count > 12)
				{
					printf("\n iterative more than 12. There is no solution. \n");
				}
			printf("\n Root is %f",x0);
			}
			return 0;
	}
