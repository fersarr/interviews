#include <iostream>
using namespace std;

//Given sorted array find index so that a[i]=i

int findIndexEqualValue(int numbers[],int size){

	int l=0;
	int r=size-1;
	int m;
	
	while(l<=r){
		m=l+(r-l)/2;
		if(numbers[m]<m){
			l=m+1;
		}
		else if(numbers[m]==m){
			return m;
		}
		else{
			r=m-1;
		}
		
		
	}

	return -1;
}

int main(){

	int numbers[]={-14,-10,2,108,109,243,285,285,285,401};
	int n=sizeof(numbers)/sizeof(int);
	
	cout<<"a[i]==i for i= "<<findIndexEqualValue(numbers,n)<<endl;;
	



	return 0;
}
