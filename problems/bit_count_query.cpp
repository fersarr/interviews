#include <iostream>
#include <iomanip>
using namespace std;

//given an int, count how many bits are set

#define MAX 66000
#define TESTS 12

int visited[MAX]; //max 16 bits every divided segment of the number


void printBinary(unsigned long long	 value)
{
	//cout<<value<<": "<<endl;
	for(int i=63;i>=0;i--){
		//cout<<(1LL<<i)<<endl;
		cout<<( ( value&(1LL<<i) ) != 0 );
	}
	cout<<endl;



}



int count(int value)
{
	if(visited[value]!=-1){
		return visited[value];
	}
	
	int curr,ans=0;
	while(value!=0){
		curr=value & (~ (value-1)); //works for negative too
		if(curr!=0)
			ans++;
		value=value^curr;
	}	

	return ans;
}


int main()
{

	long long numbers[TESTS]={0,1,2,3,4,7,10,12345,99999,890765,-7,-3};
	//12345 = 0b11000000111001
	//99999 = 0b11000011010011111
	//890765 = 0b11011001011110001101
	//-7 = 1..1001
	//-3 = 1..101
	long long number;
	int bitCount=0;
	long long sixteen1s=0b1111111111111111;
	
	for(int i=0;i<MAX;i++)
		visited[i]=-1;
	
	for(int i=0;i<TESTS;i++){
		bitCount=0;
		number=numbers[i];
		printBinary(number);
		
		for(int j=0;j<4;j++){ //divide each long long 64 bit number into 4 16 bit numbers
			unsigned long long shifted=sixteen1s<<(16*j);
			unsigned long long	 masked=(number & shifted);
			//cout<<"masked \t";
			//printBinary(masked);
			int shiftedBack=masked>>(16*j);
			//cout<<"back \t";
			//printBinary(shiftedBack);
			bitCount+=count( shiftedBack  );
			//cout<<"count: "<<bitCount<<endl;
		}
		
		cout<<setw(10)<<number<<" : "<<bitCount<<endl;
		cout<<"-----------"<<endl<<endl;
		
	}




	return 0;
}
