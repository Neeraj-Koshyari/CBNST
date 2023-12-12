/*
  Runge_Kutta_1st Method also known as Euler Method
    Formula: Yn = Yn-1 + h * f(Xn-1,Yn-1)

  Input:
    X=0, y=1, h=0.1, Xn=0.2

  Output:
    Value at 0.2 is: 0.9075

  Calculation: 
  
      |  x  |   0   |     0.1    |    0.2   |
      |-----|-------|------------|----------|
      |  y  |   1   |    0.95    |  0.9057  |
  
*/
#include<bits/stdc++.h>
using namespace std;

float eq(float x, float y){
	return (x-y)/2;
}

int main(){
	float x,y,h,xn;
	// cout<<"Enter X0: "
	cin>>x;
	
	// cout<<"Enter Y0: ";
	cin>>y;
	
	// cout<<"Enter step Length(h): ";
	cin>>h;
	
	// cout<<"Enter Xn: ";
	cin>>xn;

  cout<<setprecision(4);
	while(x!=xn){
		y+=h*eq(x,y);
		x+=h;
	}

  cout<<"Value at "<<xn<<" is: "<<y<<endl;
	return 0;
}
