#include <iostream>
#include <memory>
#include <queue>
#include <vector>
using namespace std;

//given a long sequence of numbers,output the kth smallest using few ram, O(k) space
//this is kth smallest -> max heap: insert x only if x<root or if heap.size()<k since we can only remove from the top
//similar to kth biggest - use min heap for that

int main(){

	int numbers[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	//int numbers[]={30,29,28,27,26,25,24,23,22,21,20,19};
	//int numbers[]={54,64,12,51};
	int size=sizeof(numbers)/sizeof(int);
	
	int k=8; // kth smallest
	
	priority_queue<int,vector<int>,less<int>> heap; //max heap for smallest kth
	
	for(int i=0;i<size;i++){
	
		if(heap.size()<k){
			heap.push(numbers[i]);
		}
		else if(numbers[i]<heap.top()){
			heap.pop();
			heap.push(numbers[i]);
		}
		
		
	}
	
	cout<<"Kth smallest "<<heap.top()<<endl;
	







	return 0;
}
