#include<bits/stdc++.h>
using namespace std;
long long int arr[85];
void fibo()
{
    arr[1]=1;
    arr[2]=1;
    
    for(int i=3;i<85;i++)
        arr[i]=arr[i-1]+arr[i-2];
        
}

int main()
 {
     
     int t;
     cin>>t;
     fibo();
     
     while(t--)
     {
         int n;
         cin>>n;
         
         for(int i=1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
     }
	
	return 0;
}