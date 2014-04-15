#include <iostream>
#include <random>
using namespace std;

//given an array of numbers -> shuffle them so that all permutations are equally likely


void swap(int array[],int a,int b){
	if(a!=b){
		array[a]^=array[b];
		array[b]^=array[a];
		array[a]^=array[b];
	}
}

template<class T,int N>
int arraySize(T (&array)[N]){
	return N;
}

int main(){


	random_device rd;
	default_random_engine gen(rd());
	
	//shuffle 20 times
	for(int j=0;j<20;j++){

		int numbers[]={1,2,3,4,5,6,7,8,9,10};
		int n=arraySize(numbers);
	
		for(int i=0;i<n;i++){
			uniform_int_distribution<int> dis(i,n-1);
			swap(numbers,i,dis(gen));
		}
	
		for(int i=0;i<n;i++)
			cout<<numbers[i]<<"\t";
		cout<<endl;	
	
	}










	return 0;
}
