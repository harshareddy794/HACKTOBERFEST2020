#include <iostream>
using namespace std;
unsigned long long solve(int m,int n)
{
    static int x_off[]{-2,-1,1,2}, y_off[]{1,2,2,1};
    unsigned long long ret=0;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<4;++k)
            {
                int x = i+x_off[k],
                y = j+y_off[k];
                if(x>=0 && x<m && y>=0 && y<n) ++ret;
            }
        }
    }
    unsigned long long total = m*n;
    total = total*(total-1)/2;
    return total-ret;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int m,n;
	    cin>>m>>n;
	    cout<<solve(m,n)*2<<endl;
	}
	return 0;
}