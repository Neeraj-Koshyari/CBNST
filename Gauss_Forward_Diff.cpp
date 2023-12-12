/*
  Gauss Forward formula (Numerical Interpolation)
  
  Input:
    5
    1 2 3 4 5
    1 -1 1 -1 1
    3.5

  Output:
  
    x  |   y  |   🔺 y    |  🔺2 y   |   🔺3 y  |  🔺3 y
  -----|------|-----------|-----------|----------|-----------
    1  |   1  |    -2     |     4     |    -8    |    16
    2  |  -1  |     2     |    -4     |     8    |
    3  |   1  |    -2     |     4     |          |
    4  |  -1  |     2     |           |          |
    5  |   1  |           |           |          |
  
    Value at 3.5 is: 0.375

*/
#include<bits/stdc++.h>
using namespace std;

class GaussForward{
	public:
	int n;
	vector<float> x;
	vector<vector<float>> y;
	GaussForward(){
		// cout<<"Enter Size of data: ";
		cin>>n;
		x.resize(n);
		y.resize(n,vector<float>(n));
		
		// cout<<"Enter Data of x: ";
		for(int i=0;i<n;i++)	cin>>x[i];
		
		// cout<<"Enter Data of y: ";
		for(int i=0;i<n;i++)	cin>>y[i][0];
	}
	
	void DivideAndDiffTable(){
		for(int j=1;j<n;j++){
			for(int i=0;i<n-j;i++){
				y[i][j]=y[i+1][j-1]-y[i][j-1];
			}
		}
	}
	
	float calculate(float val){
		float u=(val-x[(n-1)/2])/(x[1]-x[0]);
		float sum=y[(n-1)/2][0],fact=1,product=u;
		
		for(int i=1;i<n;i++){
			fact*=i;
			sum+=(product*y[(n+1)/2 - (i+2)/2][i])/fact;
			if(i%2==0) product*=(u + (i+1)/2);
			else	product*=(u - (i+1)/2);
		}
		
		return sum;
	}
	
	void printTable(){
		for(int i=0;i<n;i++){
			cout<<setprecision(4)<<x[i]<<" ";
			for(int j=0;j<n-i;j++)
				cout<<y[i][j]<<" ";
			cout<<endl;
		}
	}
};

int main(){
	GaussForward obj;
	obj.DivideAndDiffTable();
	obj.printTable();
	
	float val;
	// cout<<"Enter value to Pridict: ";
	cin>>val;
	cout<<"Value at "<<val<<" is: "<<obj.calculate(val)<<endl;
	
	return 0;
}
