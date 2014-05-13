#include <iostream>
using namespace std;

//find the longest repeating character

int main(){

	//string str="aaaaaaabbbbbbbbbbbbbbbbbbbbbcdasdasdstttzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzztttaaqwqwqeeeeeeeeee";
	//string str="aaaaaaabbbbbbbbbbbbbbbbbbbbbcdasdasdstttzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzztttaaqwqwqeeeeeeeeeeppppppppppppppppppppppppppppppppppppppppppppppppppp";
	//string str="aaaaappqqq";
	//string str="aaaaappqqqtttttt";
	string str="aaaaappuuuuuuuqqq";
	char prev=str[0],longest=str[0];
	int count=0,max=-1;
	for(int i=0;i<str.length();i++){
		if(str[i]==prev){
			count++;
		}
		else{
			if(count>max){
				max=count;
				longest=prev;
			}
			count=1;
		}
		prev=str[i];
	}
	
	//for last case
	if(count>max){
		max=count;
		longest=prev;
	}
			
	
	cout<<"Longest repeating: "<<longest<<" freq "<<max<<endl;
	










	return 0;
}	
