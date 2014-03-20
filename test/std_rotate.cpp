#include <iostream>
#include <algorithm>
using namespace std;

//trying out std::rotate
/*
Performs a left rotation on a range of elements.

Specifically, std::rotate swaps the elements in the range [first, last) in such a way that the element n_first becomes the first element of the new range and n_first - 1 becomes the last element.

A precondition of this function is that [first, n_first) and [n_first, last) are valid ranges.

Parameters
first	 -	 the beginning of the original range
n_first	 -	 the element that should appear at the beginning of the rotated range
last	 -	 the end of the original range
*/


int main(){

	int array[]={1,2,3,4,5,6,7,8,9,10};
	int size=sizeof(array)/sizeof(int);
	
	rotate(array,array+6,array+size-1);
	
	for(int i=0;i<size;i++)
		cout<<array[i]<<" ";
	cout<<endl;






	return 0;
}
