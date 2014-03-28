#include <iostream>
using namespace std;

//given sorted array that has numbers 1,2,3....n-1 find the duplicate number (may be repeated more than once)
//time O(log N)

int find_duplicate(int numbers[],int n){
	
	int l=0;
	int r=n-1;
	int m;
	int ans=-1;
	
			
	while(l<=r){ 
		m=l+(r-l)/2;
		if(m>=numbers[m]){ //duplicate is to the left. Use <= so it works even for duplicates that appear more than twice
			r=m-1;
			if(m>0 && (m-1)<numbers[m-1]){ //works for this but not for neighbor, then this is it.
				ans=m;
			}
		}
		else{ //duplicate is to the right
			l=m+1;
		}
	}

	return ans;
}



int find_missing(int numbers[],int n){

	int l=0;
	int r=n-1;
	int m;
	int ans=-1;
	
	while(l<=r){
		m=l+(r-l)/2;
		cout<<m<<" "<<numbers[m]<<endl;
		if(numbers[m]>=m+2){ //missing is to the left. generally numbers[m]==m+1
			r=m-1;
			if(m>0 && numbers[m-1]<((m-1)+2)){ //works for this but not for neighbor, then this is it.
				ans=m;
			}
		}
		else{
			l=m+1;
		}
	}

	return ans;
}

int main(){

	int numbers_duplicate[]={1,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
	int size=sizeof(numbers_duplicate)/sizeof(int);
	
	int numbers_missing[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,22,23};
	int size2=sizeof(numbers_missing)/sizeof(int);
	
	cout<<"Duplicate number in : "<<find_duplicate(numbers_duplicate,size)<<endl;
	cout<<"Missing number in : "<<find_missing(numbers_missing,size2)<<endl;


	return 0;

}



















