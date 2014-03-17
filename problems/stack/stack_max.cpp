#include <iostream>
#include <stack>
using namespace std;

#define MAX 1000

template<class T>
class MaxStack{
	
	public:
		void push(T value){
			if(!s.empty()){
				T maxSoFar=top().second;
				s.push(make_pair(value,(value>maxSoFar?value:maxSoFar)));
			}
			else
				s.push(make_pair(value,value));
		}
		
		void pop(){
			if(!s.empty())
				s.pop();
			else
				cout<<"ERROR: Stack is empty"<<endl;;
		}

		pair<T,T> top(){
			return s.top();
		}
		
		T max(){
			if(!s.empty())
				return s.top().second;
			cout<<"ERROR: Stack is empty"<<endl;
		}

		bool empty(){
			return s.empty();
		}	


	private:
		stack<pair<T,T>> s;

};


int main(){
	int numbers[]={1,2,3,-1,5,5,7,8,9,1,1,1,1,1,13,15};
	int n=sizeof(numbers)/sizeof(int);
	
	MaxStack<int> ms;

	for(int i=0;i<n;i++){
		ms.push(numbers[i]);
		cout<<"max so far "<<ms.max()<<endl;
	}
	
	
	cout<<"Popping all"<<endl;
	while(!ms.empty()){
		cout<<ms.top().first<<endl;
		ms.pop();
	}
	
	
	


}
