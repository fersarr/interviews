#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

//implement a queue API using an array
class EmptyListException{
	public:
		EmptyListException(string msg){
			bla=msg;
		}
	private:
		string bla;
};

template<class T>
class queue{
	public:
		queue(){
			int defaultSize=10;
			elements=new T[defaultSize]; //shared_ptr<T[defaultSize]>(new T[defaultSize]);
			size=defaultSize;
			inside=0;
			head=0;
			tail=0;
		}
		
		queue(int _size){
			elements=new T[_size]; //shared_ptr<T[_size]>(new T[_size]);
			size=_size;
			inside=0;
			head=0;
			tail=0;
		}	
		
		T top(){
			if(inside>0)
				return elements[head];
			else
				throw EmptyListException("empty list");
		}
		
		void pop(){
			if(inside>0 && head<size){
				inside--;
				elements[head++]=0;//as if 0==empty
			}
		}
	
		void push(T value){
			
			/*
			cout<<"queue state "<<endl;
			for(int i=0;i<size;i++){
				cout<<elements[i]<<" ";
			cout<<endl<<endl;
			}*/
			
			if(inside<size){
				if(tail==size){//rotate the elements so all they array space is used. Empty spaces from beggining to head-1 go at the end
					rotate(elements,elements+head,elements+size);
					head=0;
					tail=inside;
				}
				elements[tail++]=value;
				inside++;
			}
		}
		
	private:
		int size;
		int head,tail;
		int inside;
		T* elements;

};

int main(){

	queue<int> q(12);
	q.push(3);
	q.push(4);
	q.push(7);
	cout<<"Print "<<endl;
	cout<<q.top()<<endl;
	q.pop(); //remove 3
	cout<<q.top()<<endl;
	q.pop(); //remove 4
	cout<<q.top()<<endl;
	q.push(9);
	q.push(5);
	q.pop(); //remove 7
	cout<<q.top()<<endl; //print 9
	q.pop();			 //remove 9
	cout<<q.top()<<endl; //print 5
	q.pop();
	//cout<<q.top()<<endl; //empty -> -1

	q.push(3);q.push(4);q.push(5);
	q.push(3);q.push(4);q.push(5);
	q.push(3);q.push(4);q.push(5);
	q.push(3);q.push(4);q.push(5);




	return 0;
}
