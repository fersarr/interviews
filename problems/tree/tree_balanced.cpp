#include <iostream>
#include <memory>
using namespace std;

//check if a tree is balanced

template<class T>
struct node{
	T value;
	shared_ptr<node<T>> left,right;
	node(T _value){
		value=_value;
		left=nullptr;
		right=nullptr;
	}

};

#define mkshared make_shared<node<int>>
typedef shared_ptr<node<int>> tnode;



template<class T>
void printTree(shared_ptr<node<T>> & curr){
	if(curr!=nullptr){
		cout<<curr->value<<endl;
		printTree(curr->left);
		printTree(curr->right);
	}
}


//a tree is balanced if for every subtree the diff of height of left & right is <=1
template<class T>
int is_balanced(shared_ptr<node<T>> & curr,int h){

	if(curr==nullptr)
		return h-1; //this null doesn't count as a level
	
	else{
		int hl=is_balanced(curr->left,h+1);
		int hr=is_balanced(curr->right,h+1);
		cout<<"value: "<<curr->value<<" h "<<hl<<","<<hr<<endl;
		if( hl==0 || hr==0 || abs(hl-hr)>1) //subtree is unbalanced or diff>1
			return 0; //unbalanced
		else
			return max(hl,hr); //so we get max from everywhere
	}
	
}


int main(){

	tnode root=mkshared(16);
	
	//left
	tnode l1=mkshared(7);
	root->left=l1;
	tnode l2=mkshared(5);
	tnode l3=mkshared(3);
	l1->left=l2;
	l1->right=l3;
	
	//right
	tnode r1=mkshared(8);
	root->right=r1;
	 
	tnode r2=mkshared(4);
	tnode r3=mkshared(2);
	r1->left=r2;
	r1->right=r3;
	
	tnode r4=mkshared(1);
	r2->left=r4;
	
	//uncomment to unbalance
	//tnode r5=mkshared(98);
	//r4->left=r5;
		 
	printTree(root);
	bool balanced=(is_balanced(root,1)!=0); //false==zero
	cout<<"is balanced "<<balanced<<endl;;





	return 0;
}

















