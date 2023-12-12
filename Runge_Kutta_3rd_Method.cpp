/*
  Runge_Kutta_2nd Method:  
    Formula: Yn = Yn-1 + (K1 + 4*K2 + K3)/6
      K1 = h * f(Xn-1, Yn-1)
      K2 = h * f( Xn-1 + h/2, Yn-1 + K1/2 )
      K3 = h * f( Xn-1 + h, Yn-1 + h*f(Xn-1 + h, Yn-1 + K2))

  Input:
    X = 0, Y = 1, h = 0.1, Xn = 0.2

  Output:
    Value at 0.2 is: 0.9145

  Calculation: 
    Given eq f(x) = ( x - y ) / 2
  
         x  |   0   |     0.1    |    0.2   
       -----|-------|------------|----------
         y  |   1   |   0.9536   |  0.9145  
  
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
		  float K1 = h * eq(x,y);
	    float K2 = h * eq(x + h/2, y + K1/2);
	    float K3 = h * eq(x + h, y + h*eq(x + h, y + K2));
	    y += (K1 + 4*K2 + K3)/6;
	    x+=h;
	}
	cout<<"Value at "<<xn<<" is: "<<y<<endl;
	return 0;
}
