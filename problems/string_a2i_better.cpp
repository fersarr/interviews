#include <iostream>
using namespace std;

//string to int improved -> multipliying all before by 10, simiiar to rabin-karp

int main(){

	string str="9132585";
	
	int number=0;

	for(int i=0;i<str.length();i++){ //start from Most Significant NUmber because it will be multiplied by 10 each round
		number*=10; //first time nothing happens (multip by 0)
		number+=str[i]-'0';
	}

	cout<<"number "<<number<<endl;





	return 0;
}
