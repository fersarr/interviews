#include <iostream>
using namespace std;

//quick-sort sorts in-place in O(NlogN) average time but O(N^2) worst case

int n;

void swap(int array[],int a,int b){
	if(a!=b){
		array[a]^=array[b];
		array[b]^=array[a];
		array[a]^=array[b];
	}
}


//partition the array so that the left part is LESS than pivot and right part is MORE than pivot.
//this way, pivot is already in it's correct sorted position in the array
//a[lo..hi] so that a[lo..j-1] <= a[j] <= a[j+1..hi]

int partition(int array[],int lo,int hi){
	int  pivot=array[lo];
	
	while(lo<hi){
	
		//find item on low to swap (bigger than pivot)
		while(array[lo]<pivot)
			lo++;
			
		//find item on hi to swap (smaller than pivot)
		while(array[hi]>pivot)
			hi--;
			
		if(array[lo]==array[hi]) //for duplicate items, if we dont have this -> goes forever
			lo++;
			
		if(lo<hi)
			swap(array,lo,hi);
		else
			break;
		
	}

	return hi;
}


void quicksort(int array[],int lo,int hi){
	if(hi<=lo)
		return;
	int j=partition(array,lo,hi);
	
	quicksort(array,lo,j-1); //sort left partition
	quicksort(array,j+1,hi); //sort right partition
	
}




int main(){

	int numbers[]={5,86,4,86,2,69,73,11,17,1,74,34,3};
	n=sizeof(numbers)/sizeof(int);
	
	quicksort(numbers,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<numbers[i]<<" ";
	}
	cout<<endl;








	return 0;
}
