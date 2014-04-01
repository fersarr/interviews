#include <iostream>
using namespace std;

//given unsorted array of ints 0,1....n , find duplicate element
//time O(n). Since its not sorted, we cant use elimination algorithms like binary search

int main(){

	int numbers[]={1,2,3,4,4,5,6,7,8,9,10};
	int size=sizeof(numbers)/sizeof(int);
	
	
	//for duplicate
	
	int XORed_array=0;
	int XORed_complete=0;
	
	for(int i=0;i<size;i++){
		XORed_array^=numbers[i];
	}
	
	for(int i=1;i<=numbers[size-1];i++){ //this has one less element than array with duplicate
		XORed_complete^=i;
	}

	int XORed_all=XORed_array^XORed_complete;
	
	cout<<"Duplicate element is "<<XORed_all<<endl;
	
	
	//for missing
	
	int numbersMissing[]={1,2,3,4,5,6,7,9,10}; //missing 8
	int sizeMissing=sizeof(numbersMissing)/sizeof(int);
	
	
	//for duplicate
	
	XORed_array=0;
	XORed_complete=0;
	
	for(int i=0;i<sizeMissing;i++){
		XORed_array^=numbersMissing[i];
	}
	
	for(int i=1;i<=numbersMissing[sizeMissing-1];i++){ //this has one less element than array with duplicate
		XORed_complete^=i;
	}

	XORed_all=XORed_array^XORed_complete;
	
	cout<<"Missing element is "<<XORed_all<<endl;
	
	
	
	
	
	return 0;
}
