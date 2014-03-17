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
shared_ptr<node<T>> list_median(shared_ptr<node<T>> & head){
	shared_ptr<node<T>> slow=head,fast=head;
	
	while(fast!=nullptr){
		fast=fast->next;
		if(fast!=nullptr){
			slow=slow->next;
			fast=fast->next;
		}
	}	
	
	return slow;
}


template<class T>
bool check_list_equality(shared_ptr<node<T>> & head, shared_ptr<node<T>> & half2){

	shared_ptr<node<T>> curr1=head,curr2=half2;
	while(curr1!=nullptr && curr2!=nullptr){
		if(curr1->value!=curr2->value){
			return false;
		}
		curr1=curr1->next;
		curr2=curr2->next;
	}
	return true; //if all match
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
	//int numbers[]={1,2,3,4,5,6,7,8,9,10}; //even
	//int numbers[]={1,2,3,4,5,6,7,8,9}; //odd
	//int numbers[]={1,2,3,4,5,4,3,2,1}; //odd palindrome
	//int numbers[]={1,2,3,4,4,3,2,1}; //even palindrome
	int numbers[]={1,2,3,4,5,9,3,2,1}; //NOT  palindrome
	int n=sizeof(numbers)/sizeof(int);
	shared_ptr<node<int>> head;
	list_from_array(head,numbers,n);
	print_list(head);

	//get median first (n/2th element) and then reverse upper half to compare if equal
	shared_ptr<node<int>> median=list_median(head);
	if(median!=nullptr){
		cout<<"Median "<<median->value<<endl;
		shared_ptr<node<int>> reversed_half;
		if(n%2==0)
			reversed_half=list_reverse(median);
		else{
			reversed_half=list_reverse(median->next);
			median=nullptr; //delete this middle node for palindrome check	
		}
		bool palindrome=check_list_equality(head,reversed_half);
		cout<<"Palindrome "<<(palindrome?"Yes":"No")<<endl;
		
	}
	else
		cout<<"No median"<<endl;
		
	//cout<<"Reversed "<<endl;
	//shared_ptr<node<int>> reversed=list_reverse(head);
	//print_list(reversed);






	return 0;
}
