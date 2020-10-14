#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;

    int length_of_string = s.size();
    bool is_palindrome=1;
    if(length_of_string%2==0   /*if length of string is even*/){
        for(int i=0; i<=length_of_string/2; ++i){
            if(s[i]!=s[length_of_string-i-1]){
                is_palindrome=0;
            }
        }
    }else{
        for(int i=0; i<length_of_string/2; ++i){
            if(s[i]!=s[length_of_string-1-i]){
                is_palindrome=0;
            }
        }
    }
    if(is_palindrome){
        cout<<"The given string is a palindrome";
    }else{
        "The given string is not a palindrome";
    }
}