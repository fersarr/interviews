#include <iostream>
using namespace std;

//given sorted array and k, find a pair of values that sum up to k

void findPair(int numbers[],int size,int k,int & i1,int & i2){

	int l=0;
	int r=size-1;
	int sum;
	
	i1=-1;
	i2=-1;
	
	while(l<=r){
		sum=numbers[l]+numbers[r];
		if(sum<k){
			l++;
		}
		else if(sum==k){
			i1=l;
			i2=r;
			return;
		}
		else{
			r--;
		}
	}

}

int main(){

	int numbers[]={-311,-205,-147,164,200,238,314,348,422}; //if abs-sorted divide in 3 cases
	//for k=167 should return 2,6 -147+314=167
	
	int n=sizeof(numbers)/sizeof(int);
	
	int k=167;
	
	int i1,i2;
	
	findPair(numbers,n,k,i1,i2);
	
	cout<<"Pair is "<<i1<<","<<i2<<endl;
	








	return 0;
	
}
