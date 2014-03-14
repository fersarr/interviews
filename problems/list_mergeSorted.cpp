#include <iostream>
#include <memory>
//#include <boost/shared_ptr.hpp>
using namespace std;

//merge two sorted lists into a bigger sorted list

template <class T>
struct node{
	T value;
	shared_ptr<node<T>> next;
	node(){
		value=-1;
		next=nullptr;
	}
	node(T _value){
		value=_value;
		next=nullptr;
	}
};


template <class T>
void add2list(shared_ptr<node<T>> list,T value){

	shared_ptr<node<T>> curr=list;
	
	while(curr->next!=nullptr){
		curr=curr->next;
	}
	
	curr->next=make_shared<node<T> >(value);
}

template<class T>
void printList(shared_ptr<node<T>> list)
{
	cout<<"print"<<endl;
	shared_ptr<node<T>> curr=list;
	while(curr->next!=nullptr){
		cout<<"value: "<<curr->value<<endl;
		curr=curr->next;
	}

	cout<<"value: "<<curr->value<<endl;
}

template<class T>
shared_ptr<node<T>> mergeLists(shared_ptr<node<T>> list1,shared_ptr<node<T>> list2)
{
	shared_ptr<node<T>> merged;
	shared_ptr<node<T>> merged_pos;
	
	shared_ptr<node<T>> curr1=list1;
	shared_ptr<node<T>> curr2=list2;
	
	bool go=true;
	bool first=true;
	
	while(go){
		if(curr1!=nullptr && (curr1->value) < (curr2->value) ){
			if(first){
				merged=curr1;
				merged_pos=merged;
				first=false;
			}
			else{
				merged_pos->next=make_shared<node<T>>(curr1->value);
				merged_pos=merged_pos->next;
			}
			curr1=curr1->next;
		}
		else if (curr2!=nullptr) {
			cout<<"added from 2: "<<curr2->value<<endl;
			if(first){
				merged=curr2;
				merged_pos=merged;
				first=false;
			}
			else{
				merged_pos->next=make_shared<node<T>>(curr2->value);
				merged_pos=merged_pos->next;
			}
			curr2=curr2->next;
		}
		go=curr1!=nullptr || curr2!=nullptr; //keep going until the curr pointer is nullptr because it followed curr->next to more than END
		
	}

	return merged;
}

int main()
{
	int numbers1[]={2,5,7};
	int numbers2[]={3,11};

	int n1=sizeof(numbers1)/sizeof(int);
	int n2=sizeof(numbers2)/sizeof(int);
	
	shared_ptr<node<int>> list1=make_shared<node<int>>(numbers1[0]);//(-7);
	shared_ptr<node<int>> list2=make_shared<node<int>>(numbers2[0]);//(-9);
	
	for(int i=1;i<n1;i++)
		add2list(list1,numbers1[i]);	
	
	for(int i=1;i<n2;i++)
		add2list(list2,numbers2[i]);
		
	printList(list1);
	
	//merge the lists
	shared_ptr<node<int>> merged=mergeLists(list1,list2);

	cout<<endl<<"Merged: "<<endl;
	printList(merged);






	return 0;
}
