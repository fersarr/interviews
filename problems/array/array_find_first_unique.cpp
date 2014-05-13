#include <iostream>
using namespace std;

//given an unsorted array find first unique element

#define MAX 256

char charCount[MAX];


int main(){

	string str="1234567891245689"; //shouldnt be sorted. 3 and 7 are unique
	
	for(int i=0;i<MAX;i++)
		charCount[i]=0;
	
	for(int i=0;i<str.length();i++){
		charCount[str[i]]++;
	}
	
	for(int i=0;i<str.length();i++){
		if(charCount[str[i]]==1){
			cout<<"first unique char is "<<str[i]<<endl;
			break;
		}
	}

	
	
	
	





	return 0;
}
