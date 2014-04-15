#include <iostream>
using namespace std;

//given an unsorted array, find kth smallest in O(n) time. 
//if k=n/2 -> the answer is the median.
//algorithm: similar to quicksort



int n;

void swap(int array[],int a,int b){
	if(a!=b){
		array[a]^=array[b];
		array[b]^=array[a];
		array[a]^=array[b];
	}
}


int partition(int array[],int lo,int hi){
	
	int pivot=array[lo];
	
	while(lo<hi){
	
		while(array[lo]<pivot)
			lo++;
			
		while(array[hi]>pivot)
			hi--;
			
		if(array[lo]==array[hi]) //duplicate
			lo++;
			
		if(lo<hi)
			swap(array,lo,hi);
		else
			break;
	}

	return hi;
}


int kth_smallest(int array[],int k,int lo,int hi){

	int pivot=partition(array,lo,hi);
	if(lo>=hi || pivot==k)
		return pivot;
	else if(k<pivot)
		kth_smallest(array,k,lo,pivot-1); //search in lo part
	else
		kth_smallest(array,k,pivot+1,hi); //search in hi part
}

int main(){

	int numbers[]={5,86,4,86,2,69,73,11,17,1,74,34,3};
	n=sizeof(numbers)/sizeof(int);
	
	int k=6; //zero based
		
	int kth_index=kth_smallest(numbers,k,0,n-1);

	cout<<"kth smallest is "<<numbers[kth_index]<<endl;


	return 0;
}






















