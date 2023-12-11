/*
  Equation of Simpson 3/8:
      y= (3*h)/8 [ ( Y0 + Yn ) + 3*( Y1 + Y2 + Y4 +......+ Yn-2 + Yn-1 ) + 2*( Y3 + Y6 + Y9 + ...... + Yn-3 ) ]

  Input:
    a = 0, b = 1, n = 6    //Note: n should be divisible 3 in Simpson 3/8

  Output:
    Value at 6 Intervals is: 0.7854

  
  Calculation:
    Given eq: f(x) = 1 / (1 + x*x)
    h = (b-a)/n
  
        |   a   | a + (1*h)  |  a + (2*h)  |  a + (3*h)  |  a + (4*h)  |  a + (5*h)  |  a + (6*h)  |
  |-----|-------|------------|-------------|-------------|-------------|-------------|-------------|
  |  x  |   0   |   0.1666   |    0.3333   |     0.5     |    0.6666   |   0.8333    |      1      |      x is calculatred by above formula
  |-----|-------|------------|-------------|-------------|-------------|-------------|-------------|
  |  y  |   1   |   0.9729   |     0.9     |     0.8     |    0.6923   |   0.5901    |     0.5     |      y or f(x) is calculatred as putting the value of x in the given equation
  |-----|-------|------------|-------------|-------------|-------------|-------------|-------------|
        |  Y0   |     Y1     |      Y2     |     Y3      |      Y4     |     Y5      |      Y6     |

*/

#include<bits/stdc++.h>
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
	// 	Note: The Interval should be divisible by 3
	cin>>n;
	// Intervals are (Y0-Y1),(Y1-Y2),...,(Yn-1 - Yn)
	
	
	float h=(b-a)/n;
	float sum=eq(a) + eq(b);
	cout<<setprecision(4);
	
	for(int i=1;i<n;i++){
		if(i%3==0)	sum+=2*eq(a + i*h);
		else	sum+=3*eq(a + i*h);
	}
	
	cout<<"Value at "<<n<<" Intervals is: "<<((3*h)/8)*sum<<endl;
	return 0;
}
