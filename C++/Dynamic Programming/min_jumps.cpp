#include <bits/stdc++.h>
using namespace std;
int Min_jump(int a[],int n)
{
    int jum[n];
    if(a[0]==0)
    return -1;
    for(int i=1;i<n;i++)
        jum[i]=INT_MAX;

    jum[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=(i+a[i]);j>i;j--)
        {
            if(j<n)
            {
                if(jum[j]==INT_MAX)
                jum[j]=jum[i]+1;
                else
                break;
            }
        }
    }
    if(jum[n-1]==INT_MAX)
    return -1;
    else
    return jum[n-1];
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<Min_jump(a,n)<<endl;
	}
	return 0;
}
