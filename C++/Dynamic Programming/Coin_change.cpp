#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n;
	int currency[]={1,2,5,10,20,50,100,200,500,2000};
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int coins=0;
	    vector <int>ans;
	    while(n>0)
	    {
	        for(int i=9;i>=0;i--)
	        {
	            coins=n/currency[i];
	            if(coins>0)
	            {
	                for(int j=1;j<=coins;j++)
	                ans.push_back(currency[i]);
	                n=n%currency[i];
	            }
	        }
	    }
	    for(int i=0;i<ans.size();i++)
	    cout<<ans[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
