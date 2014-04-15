#include <iostream>
#include <random>
using namespace std;

//given an array of numbers, produce a sample of size K of them.
//algorithm: swap(array[i++],array[random]) k times -> so that the first k elements are the random sample

void swap(int array[],int a,int b){
	if(a!=b){
		array[a]^=array[b];
		array[b]^=array[a];
		array[a]^=array[b];
	}
}

int main(){

	int numbers[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(numbers)/sizeof(int);

	random_device rd;
	default_random_engine gen(rd());

	int sampleSize=4;
	
	for(int i=0;i<sampleSize;i++){
		uniform_int_distribution<int> dis(i,n-1);
		swap(numbers,i,dis(gen));
	}
	
	//print random sample of size sampleSize
	for(int i=0;i<sampleSize;i++){
		cout<<numbers[i]<<" ";
	}
	cout<<endl;	



	return 0;
}
