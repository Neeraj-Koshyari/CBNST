/*
  Input:
  
    4
    5 6 9 11
    12 13 14 16
    7

  Output:
  
    x  |   y  |   🔺 y   |  🔺2 y   |  🔺3 y
  -----|------|-----------|-----------|-----------
    5  |  12  |     1     |  -0.1667  |  0.05 
    6  |  13  |   0.3333  |   0.1333  |
    9  |  14  |     1     |           |
    11 |  16  |           |           |
       |      |           |           |
       
    Value at 7 is: 13.47

*/



#include<bits/stdc++.h>
using namespace std;

class NewtonDivAndDiff{
	public:
	vector<float> x;
	vector<vector<float>> y;
	int n;
	NewtonDivAndDiff(){
		//cout<<"Enter the size of table: "<<endl;
		cin>>n;
		
		x.resize(n);
		y.resize(n,vector<float>(n));
		
		//cout<<"Enter value of x: "<<endl;
		for(int i=0;i<n;i++)	cin>>x[i];
		
		//cout<<"Enter value of y: "<<endl;
		for(int i=0;i<n;i++)	cin>>y[i][0];
	}
	
	void divideAndDiffTable(){
		for(int j=1;j<n;j++){
			for(int i=0;i<(n-j);i++){
				y[i][j]=(y[i+1][j-1]-y[i][j-1])/(x[i+j]-x[i]);
			}
		}
	}
	
	float calculate(float val){
		float sum=y[0][0],product=1.0;
		for(int i=1;i<n;i++){
			product*=(val-x[i-1]);
			sum+=(product*y[0][i]);
		}
		return sum;
	}
	
	void printTable(){
		for(int i=0;i<n;i++){
			cout<<setprecision(4)<<x[i]<<" ";
			for(int j=0;j<n-i;j++)	cout<<y[i][j]<<" ";
			cout<<endl;
		}
	}
};

int main(){	
	//Enter Data:
	NewtonDivAndDiff obj;
	
	//calculate divide and difference table:
	obj.divideAndDiffTable();
	
	//print table:
	obj.printTable();
	
	//Enter unknown point:
	float val;
	cin>>val;
	
	cout<<"Value at "<<val<<" is: "<<obj.calculate(val)<<endl;
	
	return 0;
}
