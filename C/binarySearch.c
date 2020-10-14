#include<stdio.h>

int binarySearch(int a[],int n,int x) // n=size of array , x= element to be searched in the array
{
    int mid, l=0, r=n-1;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(a[mid] == x)
            return mid; // return index at which the element is present
        if(a[mid]>x)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1; // return -1 if the element is not present in the array
}

int main()
{
    int n,i,x; // n= size of array, x= element to be searched in the array
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    
    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the element to be searched for in the array: ");
    scanf("%d",&x);
    int ans = binarySearch(a,n,x);
    if(ans==-1)
        printf("\nElement not found in the array!!");
    else
        printf("\n%d is present at index %d in the array.",x,ans);
    return 0;
}