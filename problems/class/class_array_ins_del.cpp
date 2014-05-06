#include <iostream>
using namespace std;

//design a simple class to add/delete from array
class ArrayClass{
	int size;
	int *array;
	
	public:
	ArrayClass(int _size){
		size=_size;
		array=new int[size];
	}
	~ArrayClass(){
		delete[] array;
	}
	
	int getElem(int index){
		if(index<size)
			return array[index];
		else
			return -1;
	}
	void setElem(int index,int value){
		if(index<size)
			array[index]=value;
	}
};


int main(){

	ArrayClass array=ArrayClass(10);
	array.setElem(0,1);
	array.setElem(1,2);
	array.setElem(2,3);
	array.setElem(3,4);
	array.setElem(4,5);
	array.setElem(5,6);
	array.setElem(6,7);
	array.setElem(7,8);
	array.setElem(8,9);
	array.setElem(9,10);
	array.setElem(10,11);
	array.setElem(11,12);
	array.setElem(12,13);
	
	cout<<array.getElem(2)<<endl;
	cout<<array.getElem(8)<<endl;
	cout<<array.getElem(9)<<endl;
	cout<<array.getElem(10)<<endl;
	cout<<array.getElem(0)<<endl;
	
	return 0;
}
