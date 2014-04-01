#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//sorting elements of different sizes, like lines that were read from a file. 
//we sort the pointers instead to avoid swapping elements of different size

template<class T, int N>
int arraySize(T (&array)[N]){
	return N;
}

bool compPointers(const string* p1,const string * p2){
	return (*p1)<(*p2);
}

int main(){

	string lines[]={"daSdasdadasdasdas","ferfer","fer","abadsadq1das","as","pokqoew","pokemon","link"};
	int n=arraySize(lines);
	
	vector<string*> pointers;
	
	for(int i=0;i<n;i++){
		pointers.push_back(&lines[i]);
	}

	sort(pointers.begin(),pointers.end(),compPointers);
	
	cout<<"Sorted: "<<endl;
	for(int i=0;i<n;i++){
		cout<<*pointers[i]<<endl;
	}
	cout<<endl;






}
