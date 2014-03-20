#include <iostream>
#include <stack>
using namespace std;

//solve the hanoi towers with 5 disks and 3 pegs

#define PEGS 3
#define DISKS 5

stack<int> pegs[PEGS];

void transfer(int n,int from,int to,int use){
	if(n>0){
		for(int i=0;i<DISKS-n;i++) cout<<'\t';
		cout<<"Called "<<n<<endl;
		
		transfer(n-1,from,use,to);
		pegs[to].push(pegs[from].top());
		pegs[from].pop();
		
		for(int i=0;i<DISKS-n;i++) cout<<'\t';
		cout<<"Moved "<<n<<endl;
		
		transfer(n-1,use,to,from);
	}
}


int main(){

	for(int i=DISKS;i>=1;i--){
		pegs[0].push(i);
	}
	
	int from=0,to=1,use=2;
	
	transfer(DISKS,from,to,use);


	cout<<"Result "<<endl;
	for(int i=0;i<PEGS;i++){
		cout<<"Peg #"<<i<<endl;
		while(!pegs[i].empty()){
			cout<<pegs[i].top()<<endl;
			pegs[i].pop();
		}
	}






}
