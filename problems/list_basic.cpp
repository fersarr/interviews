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


template<class T>					//not const here because we are creating the list
void makeListFromArray(shared_ptr<node<T>>& head,T array[],int arraySize){

	head=make_shared<node<T>>(array[0]);
	shared_ptr<node<T>> curr=head;
	
	for(int i=1;i<arraySize;i++){
		curr->next=make_shared<node<T>>(array[i]);
		curr=curr->next;
	}
}


template<class T>
void printList(shared_ptr<node<T>> const & head){

	shared_ptr<node<T>> curr=head;
	
	while(curr!=nullptr){
		cout<<"value "<<curr->value<<endl;
		curr=curr->next;
	}

}


template<class T>
void append(shared_ptr<node<T>> const & head,T _value){
	
	shared_ptr<node<T>> curr=head;
	while(curr!=nullptr && curr->next!=nullptr){
		curr=curr->next;
	}
	
	//last element
	if(curr!=nullptr){
		curr->next=make_shared<node<T>>(_value);
	}
}

//removes the n-th element
template<class T>              //not const because we can delete first element
void remove(shared_ptr<node<T>>& head,int index){
	shared_ptr<node<T>> curr=head,previous=head,tmp;
	
	int pos=0;
	bool removed=false;
	
	while (curr!=nullptr){
		if(pos==index){
			if(index==0)
				head=curr->next;
			else{
				previous->next=curr->next;
				cout<<"Removed "<<curr->value<<endl;
			}
			removed=true;
		}
		
		previous=curr;
		curr=curr->next;
		pos++;
		
	}
	
	if(!removed){
		cout<<"Can't remove. Out of bounds?"<<endl;
	}
}


int main()
{


	int numbers[]={3,12,30,31,23,12,321,321,3,123,21,43,432};
	int n=sizeof(numbers)/sizeof(int);
	shared_ptr<node<int>> head;
	
	makeListFromArray(head,numbers,n);
	printList(head);
	
	append(head,3);
	append(head,-77);
	cout<<"Print after Added elements ---- "<<endl;

	printList(head);

	remove(head,2);
	remove(head,0);
	remove(head,12);
	cout<<"Print after Removed  ---- "<<endl;
	printList(head);









	return 0;
}
