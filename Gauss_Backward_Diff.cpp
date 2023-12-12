/*
  Gauss Backward formula (Numerical Interpolation)
  
  Input:
    6
    1931 1941 1951 1961 1971 1981
    12 15 20 27 39 52
    1966

  Output:
  
   x  |   y  |   🔺 y    |  🔺2 y   |   🔺3 y  |  🔺4 y    |  🔺5 y
  -----|------|-----------|-----------|----------|-----------|-----------
  1931 |  12  |     3     |     2     |     0    |    3      |    10
  1941 |  15  |     5     |     2     |     3    |   -7      |
  1951 |  20  |     7     |     5     |    -1    |           |
  1961 |  27  |    12     |     1     |          |           |
  1971 |  39  |    13     |           |          |           |
  1981 |  52  |           |           |          |           |
  
    Value at 1966 is: 32.34

*/
#include<bits/stdc++.h>
using namespace std;

class GaussBackward{
	public:
	int n;
	vector<float> x;
	vector<vector<float>> y;
	GaussBackward(){
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
		float u=(val-x[n/2])/(x[1]-x[0]);
		float sum=y[n/2][0],fact=1,product=u;
		
		for(int i=1;i<n;i++){
			fact*=i;
			sum+=(product*y[n/2 - (i+1)/2][i])/fact;
			if(i%2==1) product*=(u + (i+1)/2);
			else	product*=(u - i/2);
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
	GaussBackward obj;
	obj.DivideAndDiffTable();
	obj.printTable();
	
	float val;
	// cout<<"Enter value to Pridict: ";
	cin>>val;
	cout<<"Value at "<<val<<" is: "<<obj.calculate(val)<<endl;
	
	return 0;
}
