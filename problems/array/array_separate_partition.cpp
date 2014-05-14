#include <iostream>
using namespace std;

//partition the array so that 1s come first and then al the 2s

int numbers[]={1,2,1,2,1,2,2,2,1,2,1};
//int numbers[]={1,2,1,2,1,2,1,2,1,2,1};

void swap(int & a,int & b){
	if(a!=b){
		a^=b;
		b^=a;
		a^=b;
	}
}


int main(){

	//swap(numbers[0],numbers[1]);
	
	int n=sizeof(numbers)/sizeof(int);
	
	int index1=0,index2=0;
	
	for(int i=0;i<n;i++){
		if(numbers[i]==2 && numbers[index2]!=2){ //if index 2 already points to a 2, dont change until swapped
			index2=i;
		}	
		else if(numbers[i]==1){ //a 1 after a 2
			swap(numbers[i],numbers[index2]);
			index2++; //for the case that many 2s consecutive. and if we swap a  with 1 no problem
		}
	
	}
	
	for(int i=0;i<n;i++){
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
