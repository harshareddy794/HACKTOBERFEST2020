// C++ program to generate the fibonacci series in a given limit using recursion

#include <bits/stdc++.h> 
using namespace std;
int Fib(int num)
{
   if ( num == 0 )
      return 0;
   else if ( num == 1 )
      return 1;
   else
      return ( Fib(num-2) + Fib(num-1) );
}
int main()
{
   int i=0,limit,n=0;
   cout<<"Enter the limit: ";
   cin>>limit;
   cout<<"Fibonacci Series is:"<<endl;
   while(i<limit){
      cout<<Fib(n)<<endl;
      n++; i++;
   }
   return 0;
}
 
