/* DRH2SO4 */
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f(x) (3*x*x-4*x-5)
#define E 0.00001
int main()
	{
		float x0,x1,x,ecal;
		printf ("***************BISECTION METHOD*******************");
		printf("\n Enter initial value ;- \n");
		printf("\n x0 = ");
		scanf ("%f",&x0);
		printf("\n x1 = ");
		scanf("%f",&x1);
		if(f(x0)==0 || f(x1)==00)
			{
				printf("\n f(x0) or f(x1) =0 \n Please enter another initial values. \n");
			}
		else
			{
				do{
					x=(x0+x1)/2;
					if(f(x0)*f(x1)<0)
					{
						x1 = x;
					}
					else{
						x0 = x;
					}
					ecal = fabs(x1-x0);
					printf("\n x0=%f \t x1=%f \t x=%f \t f(x0)=%f \t f(x1)=%f \t ecal=%f \n",x0,x1,f(x0),f(x1),ecal);
				}while(E<ecal);
				printf(" \n The root is %f",x);
			}
			return 0;
	}
