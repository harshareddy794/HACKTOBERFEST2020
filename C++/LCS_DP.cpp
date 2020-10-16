#include <bits/stdc++.h>
using namespace std;

// function to find the length of the largest common subsequence between 2 strings
int LCS(string s,string t) 
{
    int n=s.size(),m=t.size(),i,j;

    if(!n || !m)
        return 0;

    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<LCS(s,t);
    return 0;
}