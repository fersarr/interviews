#include <iostream>
#include <set>
using namespace std;

//Print the power set of a set. Time complexity O(2^|s|) where |s| is the size of the set
//the recursion is doing a dfs with an element chosen and not chosen


//power set of S is the set of S and all the subsets of S, also the empty set.
int numbers[]={1,2,3};
//int numbers[]={1,2,3,4};
int setSize=sizeof(numbers)/sizeof(int);

#define MAX 1000 //1000 sets of 1000 elements
int sets[MAX][MAX];
int setCounter;
int printSet[MAX];


//set power set
void dfs(int index,int lowestAllowed){
	
	for(int i=0;i<index;i++){
		cout<<printSet[i];
	}
	cout<<endl;
	setCounter++;
	
	for(int i=lowestAllowed;i<setSize;i++){
		printSet[index]=numbers[i];
		dfs(index+1,i+1);
	}
	
}

int main()
{

	setCounter=0;
	dfs(0,0);	
	
	//dfs(S);
	cout<<"<empty>"<<endl;








	return 0;
}
