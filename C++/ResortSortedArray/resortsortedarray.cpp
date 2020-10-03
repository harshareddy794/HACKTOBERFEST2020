#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;//length of array
    cin>>n;
    int arr[n];
    //example of input {-8, -5, -3, -1, 3, 6, 9}
    for(int i = 0; i< n; i++){//Input array to be in General sorted order
        cin>>arr[i];
    }
    int x = -1;
    for(int i = 0; i< n; i++){//getting pointer to last negative element in array
        if(arr[i] < 0) {
            x++;
        }
        else{
            break;
        }
    }
    int  posi = x+1;
    vector<int> res(n);//resultant resorted array
    int it = 0, m;
    while(x >= 0 && posi <= n-1){
        if(abs(arr[x]) > abs(arr[posi])){
            res[it] = arr[posi];
            posi++;
        }
        else{
            res[it] = arr[x];
            x--;
        }
        it++;
    }
    while(it< n){
        while(x >= 0){
            res[it] = arr[x];
            x--;
            it++;
        }
        while(posi <= n-1){
            res[it] = arr[posi];
            posi++;
            it++;
        }
    }
    
    for(int i = 0; i< n; i++){
        cout<< res[i]<<" ";
    }
    //example of output {-1, -3, 3, -5, 6, -8, 9}
    return 0;
}
