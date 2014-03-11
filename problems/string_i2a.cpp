#include <iostream>
#include <stack>
using namespace std;

string i2a(int value)
{
	string ans="";	
	
	bool negative=value<0?true:false;
	
	if(negative)
		value*=-1;
	
	int number=value;
	int digit;
		
	stack<char> chars;
	
	while(number>0){
		digit=number%10;
		chars.push((char)(digit+'0'));
		number/=10;
	}
	
	if(chars.empty())
		ans="0";
	
	if(negative)
		chars.push('-');
			
	while(!chars.empty()){
		ans.push_back(chars.top());
		chars.pop();
	}

	
	//why str.append(""+chars.top()); doesnt work



	return ans;
}


int main()
{
/* 	int numbers[]={1,2,3,123,987654321,-1,0,-5675};
	int n=sizeof(numbers)/sizeof(int);
	
	string ans;
	
	for(int i=0;i<n;i++){
		ans=i2a(numbers[i]);
		cout<<numbers[i]<<" --> "<<ans<<endl;
	} */
	
	cout<<"bla"<<endl;
	cout<<"ab"+'a'<<endl;
	cout<<"ab"+'a'<<endl;
	cout<<""+'a'<<endl;
	
	cout<<"ab"+'a'<<endl;
	













	return 0;
}
