#include<bits/stdc++.h> 
using namespace std; 
  

int main()
{ 
    int limit;
    cout<<"Enter limit ";
    cin>>limit;
    int a=0,b=1,c=0;
    cout<<a<< endl;
    cout<<b<< endl;
    for(int i=1;i<=limit-2;i++)
    {
        c=a+b;
        a=b;
        b=c;
        cout<<c<< endl;
    }
    return 0;
}


/* 
Example - 
Enter limit 5
0
1
1
2
3
*/




