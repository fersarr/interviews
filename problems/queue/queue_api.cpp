#include <iostream>
#include <memory>
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
				head++;
			}
		}
	
		void push(T value){
			if(inside<size){
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
	cout<<q.top()<<endl; //empty -> -1






	return 0;
}
