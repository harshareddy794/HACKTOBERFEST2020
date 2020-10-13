#include<iostream>
class sam
{
	int factor=1;
	public:
		int fact(int x)
		{
		for(int i=1;i<x+1;i++)
		{
			factor=factor*i;
	    }
	    return factor;
	    }
};
int main()
{   
    sam obj;
	int x,a;
	std::cout<<"enter the number";
	std::cin>>x;
    a=obj.fact(x);
	std::cout<<"the factorial of the number is"<<a;
	return 0;
}

