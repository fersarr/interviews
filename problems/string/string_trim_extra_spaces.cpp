#include <iostream>
using namespace std;


//given a string with extra unnecessary spaces, trim the spaces in-place in o(N) time and constant mem


int main(){

	string str="          heeellla! how         are  you FRiendO?    all goood!         ";
	//string str="heeellla! how         are  you FRiendO?    all goood!";
	
	//keep track of current index and next place to put a char
	int nextPos=0;
	char lastChar=str[0];
	for(int i=0;i<str.length();i++){
		if(!(str[i]==' ' && lastChar==' ')){		
			str[nextPos]=str[i];
			nextPos++;
		}
		lastChar=str[i];
	}

	if(str[nextPos-1]==' ')//last char is space
		nextPos--;
		
	str.resize(nextPos);
	
	cout<<"START"<<str<<"DONE"<<endl;





	return 0;
}
