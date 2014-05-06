#include <iostream>
using namespace std;

//find largest two numbers in an array

int main(){

	int small=-1<<29;
	int big1=small,big2=small; //big1 is biggest
	int numbers[]={123,3,141,31,23,14,54,345,2,312,3,312,53,5435,4,36,355};

	int n=sizeof(numbers)/sizeof(int);
	
	for(int i=0;i<n;i++){
		if(numbers[i]>big1){
			big2=big1;
			big1=numbers[i];
		}
		else if(numbers[i]>big2){
			big2=numbers[i];
		}
	}

	cout<<"largest two: "<<big1<<" and "<<big2<<endl;








	return 0;
}
