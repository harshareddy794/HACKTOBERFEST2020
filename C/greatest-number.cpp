//Greatest of two numbers

#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout<<"Enter first number:"; 
    cin>>num1;
    cout<<"Enter second number:"; 
    cin>>num2;
    if(num1>num2)
    {
	cout<<"First number "<<num1<<" is the largest";
    }
    else
    {
	cout<<"Second number "<<num2<<" is the largest";
    }
    return 0;
}

/* output
Enter first number:34
Enter second number:54
Second number 54 is the largest
*/
