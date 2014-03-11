#include <iostream>
using namespace std;


//maxx difference between two numbers in an array o(N) time
//if these are stock prices each day, when is best to buy/sell?
//or if they were points in a robot path and it consumes batery depending on the distance, what's the min battery required for the path?

int main()
{
	int numbers[]={123,123,1,213,421,3,12,3,5,4,5,4,23,324,43,234,2342,2,31,31,44,425,647575};
	
	int n=sizeof(numbers)/sizeof(int);
	int maxDiff=0;
	int minNumber=numbers[0];
	
	for(int i=0;i<n;i++){
		if(maxDiff<numbers[i]-minNumber){
			maxDiff=numbers[i]-minNumber;
			cout<<"New MAX: "<<maxDiff<<" \t\trange: "<<minNumber<<" - "<<numbers[i]<<endl;
		}
		minNumber=min(minNumber,numbers[i]);
	}

	









	return 0;
}
















