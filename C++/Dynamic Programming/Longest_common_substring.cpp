#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n,m;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    string x,y;
	    cin>>x>>y;
	    int result=0;
	    int Longest[n+1][m+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0||j==0)
	            Longest[i][j]=0;
	            else if(x[i-1]==y[j-1])
	            {
	                Longest[i][j]=Longest[i-1][j-1]+1;
	                result=max(result,Longest[i][j]);
	            }
	            else
	            Longest[i][j]=0;
	        }
	    }
	    cout<<result<<endl;
	}
	return 0;
}
