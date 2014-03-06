#include <iostream>
using namespace std;

//reverse the bits of 64 bit number
#define MAX 64

void printBinary(unsigned long long	 value)
{
	//cout<<value<<": "<<endl;
	for(int i=63;i>=0;i--){
		//cout<<(1LL<<i)<<endl;
		cout<<( ( value&(1LL<<i) ) != 0 );
	}
	cout<<endl;
}

unsigned long long swap_bits(unsigned long long value,int i,int j)
{
	//cout<<"swap "<<i<<","<<j<<endl;
	//if they are different, just toggle them. Otherwise they remain unchanged
	if( (value & (1LL<<i) ) != (value & (1LL <<j) ) ){
		value=value^( (1LL<<i) | (1LL<<j) );
	}
	return value;
}

int main()
{
	unsigned long long number=7;
	printBinary(number);
	//for 32 bits numbers
	//Reverse in place by swapping
	for(int i=0;i<MAX/2;i++){
		 number=swap_bits(number,i,MAX-1-i);
	}

	printBinary(number);




	return 0;
}
