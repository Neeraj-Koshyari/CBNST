/*
  Runge_Kutta_2nd Method:  
    Formula: Yn = Yn-1 + (K1 + K2)/2
      K1 = h * f(Xn-1, Yn-1)
      K2 = h * f( Xn-1 + h, Yn-1 + K1 )

  Input:
    X=0, Y=-1, h=0.1, Xn=0.5

  Output:
    Value at 0.5 is: -0.8212

  Calculation: 
    Given eq f(x) = (-2 * x) - y
            
         x  |   0   |    0.1     |     0.2     |    0.3      |    0.4      |    0.5      
       -----|-------|------------|-------------|-------------|-------------|-------------
         y  |  -1   |   -0.915   |  -0.8570    |  -0.8236    |  -0.8124    |  -0.8212    
  
*/

#include<bits/stdc++.h>
using namespace std;

float eq(float x, float y){
	return (-2*x)-y;
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
	    float K2 = h * eq(x + h, y + K1);
	    y += (K1 + K2)/2;
	    x+=h;
	}
	cout<<"Value at "<<xn<<" is: "<<y<<endl;
	return 0;
}
