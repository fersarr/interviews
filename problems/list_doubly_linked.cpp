#include <iostream>
#include <memory>
using namespace std;

//doubly linked list

template<class T>
struct node{
	int value;
	shared_ptr<node<T>> prev,next;

	node(int _val){
		value=_val;
		prev=nullptr;
		next=nullptr;
	}
	
	node(int _val,shared_ptr<node<T>> _prev){
		value=_val;
		prev=_prev;
		next=nullptr;
	}
};


//inserts new element and returns a pointer to it
template<class T>
shared_ptr<node<T>> insert(shared_ptr<node<T>> &  curr,T value){
	if(curr==nullptr){//empty list
		curr=make_shared<node<T>>(3);
		return curr;
	}
	if(curr!=nullptr && curr->next==nullptr){
		curr->next=make_shared<node<T>>(value,curr);
		return curr->next; 
	}
	else{
		return insert(curr->next,value);
	}
	
	
}


template<class T>
void print(const shared_ptr<node<T>> & curr){
	if(curr!=nullptr){
		cout<<curr->value<<" ";
		print(curr->next);
	}
}


template<class T>
void printReverse(const shared_ptr<node<T>> & curr){
	if(curr!=nullptr){
		cout<<curr->value<<" ";
		printReverse(curr->prev);
	}
}

int main(){

	shared_ptr<node<int>> head=make_shared<node<int>>(7);
	
	insert(head,15);
	insert(head,17);
	insert(head,19);
	insert(head,24);
	insert(head,127);
	insert(head,332);
	insert(head,999);
	shared_ptr<node<int>> last=insert(head,1012);
	
	cout<<"Print doubly linked list"<<endl;
	print(head);
	cout<<endl;

	cout<<"Print REVERSEdoubly linked list"<<endl;
	printReverse(last);
	cout<<endl;
	
	return 0;
	
}































