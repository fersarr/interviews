#include <iostream>
using namespace std;

//given string with repeated letters, compress into h9e2l2o9 (letter and repetition count)

int main(){

	string str="aaaaaa_aaaaaaaaddddcefggggggghhhhiiij_pppoyiiiitq";
	int n=str.length();
	
	char prev=str[0];
	int count=0,index=0;

	for(int i=0;i<n;i++){
		if(str[i]==prev){
			count++;
		}
		else{
			str[index]=prev;
			str[index+1]=count+'0';
			index+=2;
			count=1;
		}
		prev=str[i];
	}

	//last one
	str[index]=prev;
	str[index+1]=count+'0';
	
	index+=2;
	
	//resize
	str.resize(index);
	
	cout<<str<<endl;






	return 0;
}
