#include <iostream>
#include <algorithm>
using namespace std;

//array intersection: given 2 sorted arrays, find the elements that appear in both of them

template<class T,size_t N>
int arraySize(T (&array)[N]){
	return N;
}

int main(){

	int array1[]={321,31,23,12,43,1,31,321,3,12,321,3,21,4,3424234,654,674,6,5,23,434325,4343,64765,765};
	int array2[]={31,21,536,45,75,683634648,84,2,6,36,3,645,7,47,3,53,43,25,43754,83,2,54,532,46,75,74,235};

	int n1=arraySize(array1);
	int n2=arraySize(array2);

	cout<<"sizes "<<n1<<" "<<n2<<endl;

	sort(array1,array1+n1);
	sort(array2,array2+n2);
	
	
	int i1=0,i2=0;

	while(i1<n1 && i2<n2){
		if(array1[i1]==array2[i2]){
			cout<<"common "<<array1[i1]<<endl;
			i1++;
			i2++;
		}
		else{
			if(array1[i1]<array2[i2]){
				i1++;
			}
			else{
				i2++;
			}
		}
	}	
	
	return 0;
}
