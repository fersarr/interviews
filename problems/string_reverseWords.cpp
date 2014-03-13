#include <iostream>
using namespace std;

//reverse the words in a string in O(1) space, in place
//algorithm: similar to array rotation
//reverse entire string and then reverse each word


int main()
{

	string text1="Alice likes Bob very VERY much";
	
	string text2="fer es palabraLarga";
	
	string text3="hola soy fer y tengo hambre"; //"hambre tengo y fer soy hola"

	string testText=text3;

	cout<<"Original: "<<endl<<testText<<endl<<endl;
	
	//reverse entire string
	for(int i=0;i<testText.length()/2;i++){
		int j=testText.length()-1-i; //other end of string
		
		testText[i]^=testText[j];
		testText[j]^=testText[i];
		testText[i]^=testText[j];
	}	

	cout<<"Reversed: "<<endl<<testText<<endl<<endl;

	//reverse each word
	int lastPos=0;
	for(int i=0;i<testText.length();i++){
		if(testText[i]==' ' || i==testText.length()-1){ //if space, reverse previous word
			int end= (i==(testText.length()-1) ? i+1 : i); 
			for(int j=0;j<(end-lastPos)/2;j++){
				int q=j+lastPos;
				int k=end-1-j;
				testText[q]^=testText[k];
				testText[k]^=testText[q];
				testText[q]^=testText[k];
			}
			lastPos=i+1;
		}
	}
	
	cout<<"Reversed Words: "<<endl<<testText<<endl<<endl;








	return 0;
}
