#include <iostream>
#include <vector>
using namespace std;

//implement string to int conversion function


int a2i(string str)
{
	int ans=0;
	cout<<"str "<<str<<endl;
	
	bool error=false;
	int pos=0;
	
	for(int i=str.length()-1;i>=0;i--){ //go backwards, we can't start in first (dont know 10ths place)
		int digit=str[i]-'0';
		if(digit>=0 && digit<=9){ //check if digit
			if(pos==0){
				ans+=digit;
				pos=10;
			}
			else{
				ans+=digit*pos;
				pos*=10;
			}
		}
		else if(i==0 && str[i]=='-'){
			ans=ans*-1;
		}
		else{
			error=true;
		}
	}
	
	
	if(error || str=="-")
		cout<<"result is not valid"<<endl;

	return ans;
}




int main(){
	
	string testsArr[]={"123","1","0","-1","-549","987654321","123abc","abc","-"};
	vector<string> tests(testsArr,testsArr+sizeof(testsArr)/sizeof(testsArr[0]));
	vector<string>::iterator it;
	
	int intValue;
	
	for(it=tests.begin();it!=tests.end();it++){
		intValue=a2i(*it);
		cout<<"\ta2i: "<<intValue<<endl;
	}
	
	
	return 0;
}





















