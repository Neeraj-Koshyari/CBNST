/*
  Equation of trapezoidal:
      y= h/2[ (Y0 + Yn) + 2*(Y1 + Y2 + ......+ Yn-1)]

  Input:
    a = 0, b = 1, n = 4

  Output:
    Value at 4 Intervals is: 0.0975

  
  Calculation:
    Given eq: f(x) = 1 / (x*x*x + 10)
    h = (b-a)/n
  
        |   a   | a + (1*h)  |  a + (2*h)  |  a + (3*h)  |  a + (4*h) or b  
  |-----|-------|------------|-------------|-------------|-------------|
  |  x  |   0   |    0.25    |     0.5     |    0.75     |      1      |      x is calculatred by above formula
  |-----|-------|------------|-------------|-------------|-------------|
  |  y  |  0.1  |   0.0998   |    0.0987   |   0.0958    |    0.0909   |      y or f(x) is calculatred as putting the value of x in the given equation
  |-----|-------|------------|-------------|-------------|-------------|
        |  Y0   |     Y1     |      Y2     |     Y3      |      Y4     

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

float eq(float x){
	return 1/(x*x*x + 10);
}

int main(){
	float a,b,n,sum=0;
  
 	// cout<<"Enter Lower Bound: ";
	cin>>a;
	
	// cout<<"Enter Upper Bound: ";
	cin>>b;
	
	// cout<<"Enter number of Interval: ";
	cin>>n;
	// Intervals are (Y0-Y1),(Y1-Y2),...,(Yn-1 - Yn)
	
	cout<<setprecision(4);
	float h=(b-a)/n;	  //  Each Interval Difference
	sum=eq(a) + eq(b);
	
	for(int i=1;i<n;i++){
		sum+=2*(eq(a + (i*h)));
	}
	
	cout<<"Value at "<<n<<" Intervals is: "<<(h/2)*sum<<endl;
	
	return 0;
}
