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

template<class T>
shared_ptr<node<T>> findCycle(shared_ptr<node<T>> const & head){
	
	shared_ptr<node<T>> slow=head,fast=head;
	
	int cycle=1;
	bool hasCycle=false;
	
	while(slow->next!=nullptr && fast->next!=nullptr &&fast->next->next!=nullptr){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
		
			hasCycle=true;
			
			slow=slow->next;
			while(slow!=fast){ //get cycle length
				cycle++;
				slow=slow->next;
			}
			
			//move fast from head cycle_length steps. cycle_start-fast=cycle_start-head whatever we are shy of cycle start, we have put advanced before the cycle
			fast=head;
			slow=head;
			while(cycle--){
				fast=fast->next;
			}
			//advance both one at a time. Whereevery they meet, that's cycle_start
			while(slow!=fast){
				slow=slow->next;
				fast=fast->next;
			}
			
			int stepsToMeet=0;
			
			break;
			
		}
	}
	
	
	return hasCycle?slow:nullptr;	
} 

int main()
{


	int numbers[]={3,12,30,31,23,12,321,321,3,123,21,43,432};
	int n=sizeof(numbers)/sizeof(int);
	shared_ptr<node<int>> head;
	
	makeListFromArray(head,numbers,n);
	printList(head);
	
	//create cycle
	head->next->next->next->next->next=head->next->next->next; 
	
	shared_ptr<node<int>> cycle_start=findCycle(head);
	
	
	if(cycle_start==nullptr)
		cout<<"NO CYCLE"<<endl;
	else
		cout<<"Cycle in "<<cycle_start->value<<endl;









	return 0;
}






















