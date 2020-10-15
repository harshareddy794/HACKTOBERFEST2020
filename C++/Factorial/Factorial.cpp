#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
  int fact = 1;
  int n;
  cout << "Please enter an integer: ";
  cin >> n;

  for(int index = 1; index <= n; index++)
  {
    fact = fact * index;
  }

  cout << "The factorial of " << n << " is " << fact;
  return 0;
}




