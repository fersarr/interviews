#include <iostream>
using namespace std;

//given a number, reverse (like it was a string)


int main(){

	int number =123456789;
	int reversed=0;
	
	while(number>0){
		reversed*=10;
		reversed+=number%10;
		number/=10;
	}

	cout<<"reversed "<<reversed<<endl;




	return 0;
}
