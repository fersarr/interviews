#include <iostream>
#include <cmath>
using namespace std;

//given array of non-negative integers, find the duplicates (one or more, repeteated may be more than once)
//NUMBERS HAVE TO BE IN RANGE OF ARRAY 0,1,2,..,n-1
//make visited negative
//0 is a special case

int abs(int value){
	if(value<0)
		return -value;
}

int main(){
	int numbers[]={0,1,2,3,4,6,7,8,9,1,0,7,5,4};
	int n=sizeof(numbers)/sizeof(int);
	
	bool zeroSeen=false;

	for(int i=0;i<n;i++){
		//cout<<"num "<<endl;
 		if(numbers[i]==0){
			if(zeroSeen==true){
				cout<<"dup 0"<<endl;
			}
			zeroSeen=true;
		}
		if(numbers[abs(numbers[i])]<0){ //duplicate
			cout<<"dup "<<abs(numbers[i])<<endl;
		}
		else{
			numbers[abs(numbers[i])]=-numbers[abs(numbers[i])]; //only if positive get number in number's index and restore it there but negative (marked visited)
		}
	
	}





	return 0;
}
