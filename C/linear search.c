#include<stdio.h>
#define max 5
int main()
{
	int A[max],i,key,count=0;
	printf("enter the elements\n");
	for(i=0;i<max;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("enter the element you want to search\n");
	scanf("%d",&key);
	for(i=0;i<max;i++)
	{
		if(key==A[i])
		count=count+1;
		else
		continue;
	}
	printf("the element  %d is %d times in the array ",key,count);
return 0;	
}

