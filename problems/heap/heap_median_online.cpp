#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//given a stream of numbers, determine the online median (on the fly)
//we use two heaps, one minheap and one maxheap. keep them balanced respect of each other int erms of elements contained

int main(){

	int numbers[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	//int numbers[]={30,29,28,27,26,25,24,23,22,21,20,19};
	//int numbers[]={54,64,12,51};
	int size=sizeof(numbers)/sizeof(int);


	priority_queue<int,vector<int>,greater<int>> minHeap;
	priority_queue<int,vector<int>,less<int>> maxHeap;
	
	
	for(int i=0;i<size;i++){
		if(!maxHeap.empty() && numbers[i]>maxHeap.top() ){
			minHeap.push(numbers[i]);
		}
		else{
			maxHeap.push(numbers[i]);
		}
		
		
		if(!maxHeap.empty() && (minHeap.size()+1)<maxHeap.size()){
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if(!minHeap.empty() && (maxHeap.size()+1)<minHeap.size()){
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		
		cout<<"Online median: "<<(maxHeap.size()>minHeap.size()?maxHeap.top():minHeap.top())<<endl<<endl;
	}

	return 0;
}
