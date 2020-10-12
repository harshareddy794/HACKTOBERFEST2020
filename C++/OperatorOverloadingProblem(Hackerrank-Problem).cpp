/*
Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length , breadth , and height .
The default constructor of the class should initialize , , and  to .
The parameterized constructor Box(int length, int breadth, int height) should initialize Box's  and  to length, breadth and height.
The copy constructor BoxBox ) should set  and  to 's  and , respectively.
Apart from the above, the class should have  functions:
int getLength() - Return box's length
int getBreadth() - Return box's breadth
int getHeight() - Return box's height
long long CalculateVolume() - Return the volume of the box
Overload the operator  for the class Box. Box   Box  if:
 < 
 <  and ==
 <  and == and ==
Overload operator  for the class Box().
If  is an object of class Box:
 should print ,  and  on a single line separated by spaces.
Constraints
Two boxes being compared using the  operator will not have all three dimensions equal.
*/

#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
class Box{
    long long  l,b,h;
    public:
    Box(){
        l=0;
        b=0;
        h=0;
    }

    Box(int length, int breadth, int height){
        l=length;
        b=breadth;
        h=height;
    }
    Box(const Box &B){
        l=B.l;
        b=B.b;
        h=B.h;
    }
    int getLength() {
        return(l);
    }
    int getBreadth(){
        return(b);
    }
    int getHeight() {
        return(h);
    }
    long long CalculateVolume(){
        return (long long)(l*b*h);

    }

friend bool operator < ( Box &A,Box &B){
        if( (A.l < B.l) || ((A.b < B.b) && (A.l == B.l)) || ((A.h < B.h) && (A.l == B.l) && (A.b == B.b)) ){
            return true;
        }else{
            return false;
        }
    }
    
    friend ostream& operator<< (ostream& output, const Box& B){
        output << B.l << " " << B.b << " " << B.h;
        return output;
    }
};

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
