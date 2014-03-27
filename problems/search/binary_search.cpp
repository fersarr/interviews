#include <iostream>
using namespace std;

//binary search. find K in sorted array

int binSearch(int numbers[],int size,int k){
	
	int l=0;
	int r=size-1;
	int m;
	
	while(l<=r){
		m=l+(r-l)/2;
		if(numbers[m]<k){
			l=m+1;
		}
		else if(numbers[m]==k){
			return m;
		}
		else{
			r=m-1;
		}
	}
	
	return -1; //not found
}



int main(){

	//int numbers[]={7};
	int numbers[]={-14,-10,2,108,109,243,285,285,285,401};
	//int numbers[]={};
	//int numbers[]={1,2,3};
	//int numbers[]={1,2,3,4};
	
	int n=sizeof(numbers)/sizeof(int);
	int k=-10; //number to search for
		
	cout<<"BinSearch: "<<binSearch(numbers,n,k)<<endl;
	












	return 0;
}
