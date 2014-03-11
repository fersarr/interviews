#include <iostream>
using namespace std;

int main()
{
	//int numbers[]={123,123,1,213,421,3,12,3,5,4,5,4,23,324,43,234,2342,2,31,31,44,425,647575};
	int numbers[]={1,2,3,4,2,2,2,2,2,2,2,1,2,3,4,5,6,1,1,1,1,2,3,4,5,6,7};
	             //0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7
	int n=sizeof(numbers)/sizeof(int);
	
	int longest=1;
	int count=1;
	int start=0;
	
	
	//time O(N)
/* 	for(int i=1;i<n;i++){
		if(numbers[i]>numbers[i-1])
			count++;
		else{
			if(count>longest){
				longest=count;
				cout<<"Longest ("<<count<<"): "<<start<<" to "<<i-1<<endl;	
			}
			count=1;
			start=i;	
		}
	} */
	
	//we can do a little better with a heuristic advancing i+L when number[i]<number[i+1]
	//for most cases. But is the same for the worst case (example: alternating 1s and 0s)

	int i=0;
	while(i<n){
		if(numbers[i]>numbers[i-1]){
			count++;
			i++;	
		}
		else{
			if(count>longest){
				longest=count;
				cout<<"Longest ("<<count<<"): "<<start<<" to "<<i-1<<endl;	
			}
			count=0;
			int j=i+longest;
			
			bool skipable=false;
			if(j<n)
				skipable=true;
			int before_count=0;
			while(j>=i && j>0 && skipable==true){
				if(numbers[j]<=numbers[j-1])
					break;
				before_count++;
				j--;
				cout<<"\t went back: ["<<j<<"]="<<numbers[j]<<endl;
			}
			
			if(skipable)
				i=i+longest;
			else
				i++;
			
			count=count+before_count;
			start=i-before_count;
				
		}
	}




	return 0;
}
