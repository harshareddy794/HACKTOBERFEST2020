//fibbonaci series
using namespace std;
#include<iostream>
class sam
{
	int t1=0,t2=1,t3;
	public:
	int fib(int n)
	{
		cout<<"the terms of the fibbonaci series are ";
		cout<<t1<<ends<<t2<<ends;
		for(int i=1;i<=n;i++)
		{
			t3=t2+t1;
			t1=t2;
			t2=t3;
			cout<<t3<<ends;
		}
	  	
	}
};
int main()
{
	sam obj;
	int n;
	cout<<"enter the no of terms";
	cin>>n;
	obj.fib(n);
	return 0;
}




