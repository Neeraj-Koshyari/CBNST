/*
    Newton's Backward Difference formula (Numerical Interpolation)
  Input:
    5
    1891 1901 1911 1921 1931
    46 66 81 93 101
    1925

  Output:
  
    x  |   y  |   🔺 y    |  🔺2 y   |   🔺3 y  |  🔺3 y
  -----|------|-----------|-----------|----------|-----------
  1891 |  46  |           |           |          |    
  1901 |  66  |    20     |           |          |
  1911 |  81  |    15     |    -5     |          |
  1921 |  93  |    12     |    -3     |     2    |
  1931 | 101  |     8     |    -4     |    -1    |    -3
  
    Value at 1925 is: 96.8368


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
			for(int i=n-1;i>=j;i--){
				y[i][j]=y[i][j-1]-y[i-1][j-1];
			}
		}
	}
	
	float calculate(float val){
		float u=(val-x[n-1])/(x[1]-x[0]);
		float sum=y[n-1][0],fact=1,product=u;
		
		for(int i=1;i<n;i++){
			fact*=i;
			sum+=(product*y[n-1][i])/fact;
			product*=(u+i);
		}
		
		return sum;
	}
	
	void printTable(){
		for(int i=0;i<n;i++){
			cout<<x[i]<<" ";
			for(int j=0;j<=i;j++)
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
	// cout<<"Enter value to Pridict: ";
	cin>>val;
	cout<<"Value at "<<val<<" is: "<<obj.calculate(val)<<endl;
	
	return 0;
}
