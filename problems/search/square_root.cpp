#include <iostream>
using namespace std;

//given a float, calculate (find) its square root
//we can binary search the answer (bisection method) since its a monotincally increasing function

#define EPS 1e-3
#define STEP 1e-9 	

double abs(double val){
	return val>=0?val:val*-1.0;
}	

double square_root(double x){
	double ans;

	double l=0.0;
	double r=x;
	double m;
	
	while(l<=r){
		m=l+(r-l)/2.0;
		cout<<"m "<<m<<endl;
		if(abs(m*m-x)<EPS){
			return m;
		}
		else if(m*m<x){
			l=m+STEP;
		}
		else{
			r=m-STEP;
		}
	
	}

	return -1;
}



int main(){


	double x=3132140.0;
	cout<<"sqrt of "<<x<<" is: "<<square_root(x)<<endl;
	
	











	return 0;
}
