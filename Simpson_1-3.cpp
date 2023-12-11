/*
  Equation of Simpson 1/3:
      y= h/3 [ ( Y0 + Yn ) + 4*( Y1 + Y3 + ......+ Yn-1 ) + 2*( Y2 + Y4 + ...... + Yn-2 ) ]

  Input:
    a = 0, b = 1, n = 4

  Output:
    Value at 4 Intervals is: 0.7854

  
  Calculation:
    Given eq: f(x) = 1 / (1 + x*x)
    h = (b-a)/n
  
        |   a   | a + (1*h)  |  a + (2*h)  |  a + (3*h)  |  a + (4*h) or b  
  |-----|-------|------------|-------------|-------------|-------------|
  |  x  |   0   |    0.25    |     0.5     |    0.75     |      1      |      x is calculatred by above formula
  |-----|-------|------------|-------------|-------------|-------------|
  |  y  |   1   |   0.9411   |     0.8     |    0.64     |     0.5     |      y or f(x) is calculatred as putting the value of x in the given equation
  |-----|-------|------------|-------------|-------------|-------------|
        |  Y0   |     Y1     |      Y2     |     Y3      |      Y4     

*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

float eq(float x){
	return 1/(1 + x*x);
}

int main(){	
	float a,b,n;
	// cout<<"Enter lower Bound: ";
	cin>>a;
	
	// cout<<"Enter upper Bound: ";
	cin>>b;
	
	// cout<<"Enter the number of Interval: ";
	// 	Note: The Interval should be divisible by 2 for Simpson 1/3
	cin>>n;
	// Intervals are (Y0-Y1),(Y1-Y2),...,(Yn-1 - Yn)
	
	
	float h=(b-a)/n;
	float sum=eq(a) + eq(b);
	cout<<setprecision(4);
	
	for(int i=1;i<n;i++){
		if(i%2==0)	sum+=2*eq(a + i*h);
		else	sum+=4*eq(a + i*h);
	}
	
	cout<<"Value at "<<n<<" Intervals is: "<<(h/3)*sum<<endl;
	return 0;
}
