#include <iostream>
using namespace std;

//rotate (shift) an array in O(N) using O(1) space

void swap(int array[],int i1,int i2){
	array[i1]^=array[i2];	
	array[i2]^=array[i1];
	array[i1]^=array[i2];
}


void reverse(int array[],int n){
	for(int i=0;i<n/2;i++){
		swap(array,i,n-1-i);
	}
}


void rotate(int array[],int rot,int n){
	int groupsize=n-rot%n;
	reverse(array,groupsize);
	reverse(array+groupsize,n-groupsize);
	reverse(array,n);
	cout<<"rotated "<<rot<<endl;
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	//int array[]={1,2,3,4,5,6,7,8,9};
	int rotations[]={1,2,3,4,15};

	//int n=sizeof(numbers)/sizeof(int);
	int nrot=sizeof(rotations)/sizeof(int);
	
	for(int i =0; i<nrot;i++){
		int array[]={1,2,3,4,5,6,7,8,9};
		int n=sizeof(array)/sizeof(int);
		rotate(array,rotations[i],n);
	}
	
	
	
		
		
	return 0;
}

