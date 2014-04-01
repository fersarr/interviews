#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//given a text, find the string that is repeated most closely, the nearest repetition.


//get the size of an array reference using templates mind the (&array)
template<class T,size_t n>
size_t arraySize(T const  (&array)[n]){
	return n;
}

int main(){


	
	string words[]={"all","work","and","no","play","makes","for","no","work","no","fun","and","no","results"};

	int size=sizeof(words)/sizeof(words[0]);
	int closest=1<<30-1;
	int index=0;
	
	cout<<"size "<<arraySize(words)<<endl;
	
	unordered_map<string,int> lastPos;
	
	for(int i=0;i<size;i++){
		if(lastPos.find(words[i])!=lastPos.end()){ //if seen before
			if(closest>i-lastPos[words[i]]){
				closest=i-lastPos[words[i]];
				index=i;
			}
		}
		lastPos[words[i]]=i;
	}
	
	cout<<"closest repetition is "<<words[index]<<" at "<<index<<" distance "<<closest<<endl;
	
	
	










	return 0;
}
