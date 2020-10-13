#include <stdio.h>
void rotate( int arr[],int arr_size, int arr_rot);
 void print_arr(int arr[], int n);
int main() {
	//code
	int test_case, arr_size, arr_rot,arr[100],i;
	printf("hello");
	scanf("%d",&test_case);
	scanf("%d %d",&arr_size,&arr_rot);
	for(int i =0;i<arr_size-1;i++)
	{
	    scanf("%d",&arr[i]);
	}
	
	// for(int i =0;i<arr_size-1;i++)
	// {
	//     printf("%d -> ",arr[i-1]);
	// }
	
// printf("%d",arr[i]);
printf("Before rotation \n");
	print_arr(arr,arr_size);
	 

for(i=0;i<arr_rot;i++){
rotate(arr,arr_size,arr_rot);
}

	 printf("after rotation \n");
	 print_arr(arr,arr_size);
	return 0;
}



void rotate( int arr[], int arr_size, int arr_rot){
	int i ;
	int temp = arr[0];
	for (i=0; i<arr_size-1;i++){
	arr[i]=arr[i+1];
	 arr[arr_size-1]=temp;
	}
	
}


 void print_arr(int arr[], int size)
{
	for (int i = 0; i < size-1 ; i++)
	{
		printf("%d-> ",arr[i]);
	}
}