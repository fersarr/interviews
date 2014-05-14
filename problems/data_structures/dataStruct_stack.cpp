#include <iostream>
#include <vector>
using namespace std;

//implement a stack

template<class T>
class Stack{
	public:
		Stack(int _size){
			stack.resize(_size);
			index=0;
		}
		T pop(){
			if(index>=0){
				index--;
				return stack[index];
			}
		}
		T top(){
			if(index>=0){
				return stack[index];
			}
		}
		void push(T value){
			if(index<stack.size()){
				stack[index++]=value;
			}
		}
	
	private:
		vector<T> stack;
		int index;
};

int main(){

	Stack<int> myStack=Stack<int>(10);	

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	cout<<myStack.top()<<endl;
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	


	return 0;
}
