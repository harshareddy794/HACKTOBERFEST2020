#include <iostream>
using namespace std;

int main()
{
   int i,j,k,space=10; // to print the pyramid in center, you can also increase the # of spaces
   
for (int i=0;i<=5;i++)
{
   for (int k=0;k<space;k++)
{
   cout<<" ";
}
for (int j=0;j<2*i-1;j++)
{
   cout<<"*";
}
   space--;
   cout<<endl;
}
cin.get(); /*use this to wait for a keypress*/} 
