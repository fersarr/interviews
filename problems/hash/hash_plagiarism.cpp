#include <iostream>
using namespace std;

//try to find words inside a text. Match strings. Rabin - karp. Plagiarism.

int main(){

	int base=256,mod=997;

	string text="hola  soy fer como aandas fer chofer adsamiodmqwifer adasdaswqdfeferdsadasdasfer fer";
	string pattern="fer";
	
	long long p_hash=0,t_hash=0,biggestBase=1;
	
	for(int i=0;i<pattern.size();i++){
		p_hash=(p_hash*base+pattern[i])%mod;
		t_hash=(t_hash*base+text[i])%mod;
		biggestBase=i>0?biggestBase*base:1;
	}

	cout<<"p_hash "<<p_hash<<" t_hash "<<t_hash<<endl;	
	
	for(int i=pattern.size();i<text.size();i++){
			t_hash-=(text[i-pattern.size()]*biggestBase)%mod;
			if(t_hash<0){
				t_hash+=mod;
			}
			
			t_hash=(t_hash*base+text[i])%mod;
			
			//cout<<"t hash"<<t_hash<<endl;
			
			if(t_hash==p_hash){
				cout<<"match at "<<i-pattern.size()<<endl;
			}	
	}
	
	//last case
	if(t_hash==p_hash){
		cout<<"found at beggining "<<0<<endl;
	}









	return 0;
}
