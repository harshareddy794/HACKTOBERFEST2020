#include<iostream>
 using namespace std;
 
    int uniquePaths(int m, int n) {
        int A[m][n],i,j;
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(i==m-1||j==n-1)
                {
                    A[i][j]=1;
                }
                else
                {
                    A[i][j]=A[i][j+1]+A[i+1][j];
                }
            }
        }
        return A[0][0];       
    }
    
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n);
}
