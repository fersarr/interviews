#include <iostream>
#include <iomanip>
using namespace std;

//check if the given number has bit parity.

#define TESTS 12

int main()
{
	int numbers[TESTS]={0,1,2,3,4,7,10,12345,99999,890765,-7,-3};
	int bits=32;
	
	int curr,lowestSetBit;
	int bitCount=0;
	for(int i=0;i<TESTS;i++){
		bitCount=0;
		curr=numbers[i];
		while(curr!=0){
			lowestSetBit=curr & (~(curr-1)); //get lowest set bit in curr			
			if(curr!=0)
				bitCount++;
				
			curr=curr^lowestSetBit; //if lowest is zero it wont toggle with XOR
		}
		
	cout<<setw(10)<<numbers[i]<<": Bit count "<<bitCount<<" Parity "<<!(bitCount%2)<<endl;
	}





	return 0;
}
