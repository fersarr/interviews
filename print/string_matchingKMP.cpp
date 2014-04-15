#include <iostream>
using namespace std;

//KMP string matching time O(m+n) N=TEXT.LENGTH() and m is patterns length
//preprocessing (fail function) takes at most 2*length(pattern)
//algorithm: 2*length(text) - length(pattern) - 1
//thus the overall complexity is O(m+n) and no more m + 2*n 

#define MAX 1000

char fail[MAX]; //fail size: pattern.length()+1, counting empty string

void build_fail(string pattern){
	
	int m=pattern.length();
	fail[0]=0;
	fail[1]=0;

	int j;
	for(int i=2;i<=m;i++){
		j=fail[i-1];
		while(1){ //go back according to fail[j] when no match
			if(pattern[i-1]==pattern[j]){
				fail[i]=j+1;
				break;
			}
			
			if(j==0){
				fail[i]=0;
				break;
			}
			
			j=fail[j];
		}
		
	}
}

int main(){
	
	string pattern="ababac";
	string text="hey bacman itsaba fer andababac fersarr ababac to";
	                     //10           //25  //31
	build_fail(pattern);

	//find matches
	http://www.lakersnation.com/kobe-bryant-believes-lakers-turnaround-starts-with-jim-and-jeanie-buss/2014/03/12/#18
	int n=text.length();
	int m=pattern.length();
	
	
	int i=0,j=0;
	while(i<n){
		if(text[i]==pattern[j]){
			i++;
			j++;
			if(j==m){
				cout<<"match in "<<i-1<<endl;
			}
		}
		else if(j>0)
			j=fail[j];
		else //move in text, reached empty string and failed to expand
			i++;
	}














	return 0;
}










