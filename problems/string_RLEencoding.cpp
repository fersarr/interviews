#include <iostream>
using namespace std;

//string: run length encoding (RLE) is a compression algorithm that counts the repeated letters
// so aaa -> a3
//only letters & spaces input

#define MAX 100

int main()
{
	string text="aaaaaaaaaaabbbcaaa     hola soyyy fer che como eeesssttas menem blabllllla";
	//string text="aaaaaaaaaaabbbcaaa     hola soyyy fer che como eeesssttas menem blablllll";
	
	string encoded(text.length(),'_'); //initialized
	
	
	int count=1;
	int i=1;
	while(i<text.length()){
		if(text[i]==text[i-1]){
			count++;
		}
		else{
			cout<<text[i-1]<<count;
			count=1;		
		}

		if(i==text.length()-1) //if last
				cout<<text[i]<<count;
				
		i++;
	}

	
	cout<<endl;








	return 0;
}
