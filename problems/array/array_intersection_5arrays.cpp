#include <iostream>
#include <algorithm>
using namespace std;

//find common elements in five 5 arrays

#define nArrays 5
#define cols 10

bool noneFinished(int indices[],int limit){
	bool ans=true;
	for(int i=0;i<nArrays;i++){
		if(indices[i]>=limit)
			ans=false; //one has finished
	}
	
	return ans;
}

bool allSame(int indices[],int numbers[][cols]){
	bool ans=true;
	for(int i=0;i<nArrays-1;i++){
		if(numbers[i][indices[i]]!=numbers[i+1][indices[i+1]])
			ans=false;
	}
	
	return ans;
}

int main(){

	int numbers[nArrays][cols]={{1,2,3,4,5,6,7,8,9,10},
					  			{10,19,18,7,16,15,4,13,12,11},
					  			{10,29,28,7,16,25,4,23,22,12},
					  			{30,39,38,7,36,35,4,13,32,11},
					 			{90,99,98,7,96,95,4,93,92,19}
								};
	
	for(int i=0;i<nArrays;i++){
		sort(numbers[i],numbers[i]+cols);
	}

	
	int indices[nArrays]={0,0,0,0,0};
	
	while(noneFinished(indices,cols)){ //if one aray is finished, then no more common elements will be found
		if(allSame(indices,numbers)){
			cout<<"Common ELement: "<<numbers[0][indices[0]]<<endl;
			indices[0]++;
		}
		for(int i=0;i<nArrays-1;i++){
			//cout<<"index "<<i<<": "<<indices[i]<<endl;
			if(numbers[i][indices[i]]<numbers[i+1][indices[i+1]]){
				if(indices[i]<cols)
					indices[i]++;
			}
			else if(numbers[i][indices[i]]>numbers[i+1][indices[i+1]]){
				if(indices[i+1]<cols)
					indices[i+1]++;
			}
		}
	}
	

	return 0;
}
