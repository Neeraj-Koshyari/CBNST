/*
  Newton's Forward Difference formula (Numerical Interpolation)
  
  Input:
   5
  1891 1901 1911 1921 1931
  46 66 81 93 101
  1895

  Output:
  
    x  |   y  |   🔺 y    |  🔺2 y   |   🔺3 y  |  🔺4 y
  -----|------|-----------|-----------|----------|-----------
  1891 |  46  |    20     |    -5     |     2    |    -3
  1901 |  66  |    15     |    -3     |    -1    |
  1911 |  81  |    12     |    -4     |          |
  1921 |  93  |     8     |           |          |
  1931 | 101  |           |           |          |
  
    Value at 1895 is: 54.8528

*/

#include<bits/stdc++.h>
using namespace std;

class NewtonForward{
	public:
	int n;
	vector<float> x;
	vector<vector<float>> y;
	NewtonForward(){
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
		float u=(val-x[0])/(x[1]-x[0]);
		float sum=y[0][0],fact=1,product=u;
		
		for(int i=1;i<n;i++){
			fact*=i;
			sum+=(product*y[0][i])/fact;
			product*=(u-i);
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
	NewtonForward obj;
	obj.DivideAndDiffTable();
	obj.printTable();
	
	float val;
	// cout<<"Enter the value to Pridict: ";
	cin>>val;
	cout<<"Value at "<<val<<" is: "<<obj.calculate(val)<<endl;
	
	return 0;
}
