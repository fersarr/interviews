#include <iostream>
using namespace std;

//lower bound binary search: find minimum index with value 6 or greater
//first element larger than k

int lowerBound(int numbers[],int size,int k){

	int l=0;
	int r=size-1;
	int m;
	int saved=-1;
	
	while(l<=r){
		m=l+(r-l)/2;
		if(numbers[m]>=k){ 
			saved=m;
			r=m-1;
		}
		else{
			l=m+1;
		}
	}

	return saved; //-1 if not found
}

int main(){

	int numbers[]={-14,-10,2,108,109,243,285,285,285,401};
	int n=sizeof(numbers)/sizeof(int);
	
	int k=200;
	
	cout<<"Lower bound: "<<lowerBound(numbers,n,k)<<endl;;
	



	return 0;
}
