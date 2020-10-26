// Here is a program for knasack problem
// dynamic solution for greedy algorithm

#include <stdio.h>
int max(int a, int b)
{
if(a>b) return a; else return b;
}

int knapsack(int W, int wt[], int val[], int n)
{
int i, w;
int K[n+1][W+1];

for (i = 0; i <= n; i++)
{
for (w = 0; w <= W; w++)
{
if (i==0 || w==0) K[i][w] = 0;
else if (wt[i-1] <= w)
K[i][w] = max(K[i-1][w],K[i-1][w-wt[i-1]]+val[i-1]); else
K[i][w] = K[i-1][w];
}
}

return K[n][W];
}

int main()
{
int W,n;
int val[20],wt[20];
printf("\n ka.patel prachi ... 170410107034");
printf("\nenter n: ");
scanf("%d",&n);
printf("\nenter total weight capacity:");
scanf("%d",&W);
printf("\n enter value and weiht of object::");
for(int i=0;i<n;i++)
{
    printf("\nvalue of %d :",i+1);
    scanf("%d",&val[i]);
    printf("\nweight of %d :",i+1);
    scanf("%d",&wt[i]);
}
printf("\nValue = %d\n", knapsack(W, wt, val, n)); return 0;
}
