#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct node{
	T value;
	shared_ptr<node<T>> next;
	node(T _value){
		value=_value;
		next=nullptr;
	}
	
};


template<class T>
void list_from_array(shared_ptr<node<T>> & head,int array[],int n){
	
	if(n>0)
		head=make_shared<node<T>>(array[0]);
	
	shared_ptr<node<T>> curr=head;
	
	for(int i=1;i<n;i++){
		curr->next=make_shared<node<T>>(array[i]);
		curr=curr->next;
	}
}

template<class T>
shared_ptr<node<T>> list_reverse(shared_ptr<node<T>> & head){
	shared_ptr<node<T>> curr,previous,future;
	
	if(head!=nullptr){
		curr=head->next; //start in second item
		previous=head;
		head->next=nullptr; //the end of reversed
	}
	
	while(curr!=nullptr){
		future=curr->next;
		curr->next=previous;
		previous=curr;
		curr=future;		
	}
	
	return previous;
}

template<class T>
void print_list(shared_ptr<node<T>> const &head){
	shared_ptr<node<T>> curr=head;
	
	while(curr!=nullptr){
		cout<<curr->value<<" ";
		curr=curr->next;
	}
	cout<<endl;

}

int main(){

	//int numbers[]={}; //empty
	//int numbers[]={8}; //one element
	int numbers[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(numbers)/sizeof(int);
	shared_ptr<node<int>> head;
	list_from_array(head,numbers,n);
	print_list(head);

	cout<<"Reversed "<<endl;
	shared_ptr<node<int>> reversed=list_reverse(head);
	print_list(reversed);






	return 0;
}
