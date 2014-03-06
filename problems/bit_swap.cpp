#include <iostream>
using namespace std;

//given 64 bit number and two indices i,j swap the bits in i and j. 
//test cases: i==j

void printBinary(unsigned long long	 value)
{
	//cout<<value<<": "<<endl;
	for(int i=63;i>=0;i--){
		//cout<<(1LL<<i)<<endl;
		cout<<( ( value&(1LL<<i) ) != 0 );
	}
	cout<<endl;
}


unsigned long long swap_bits(unsigned long long value, int i,int j)
{
	//check to see if they are on
	bool tmpi=(value & (1LL << i)) != 0 ; 
	bool tmpj=(value & (1LL << j)) != 0 ;
	
	//move i to j
	if(tmpi) //if i==on turn on j
		value=(value | (1LL << j) ); //turn on
	else
		value=(value & ~(1LL << j) ); //turn off
	
	
	//move j to i
	if(tmpj) //if i==on turn on j
		value=(value | (1LL << i) );
	else
		value=(value & ~(1LL << i) );
	
	return value;
} 


unsigned long long swap_bits_better(unsigned long long value, int i,int j)
{
	//only change if they are different
	if ( (value & (1LL << i)) != (value & (1LL << j)) ){
		//we can just xor them to toggle
		value=value^(1LL<<i | 1LL<<j);		
	}
	return value;
} 



int main()
{
	unsigned long long value= 2549685050594;
	
	printBinary(value);
	
	//value=swap_bits(value,1,62);
	
	value=swap_bits_better(value,1,62);
	
	printBinary(value);











	return 0;
}
