#include <iostream>
#include <memory>
#include <sstream>
using namespace std;

//given a binary tree, check if it satisfies BST property

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


//reconstruct BST from preorder
int index;
template<class T>
void reconstructBST(shared_ptr<node<T>> & curr,T preorder[],int maxAllowed,int size){
	
	if(index==size)
		return;
	
	if(preorder[index]<curr->value){ //go left
		curr->left=make_shared<node<T>>(preorder[index]);
		index++;
		reconstructBST(curr->left,preorder,curr->value,size);
	}
	if(preorder[index]>curr->value && preorder[index]<maxAllowed){ //go right
		curr->right=make_shared<node<T>>(preorder[index]);
		index++;
		reconstructBST(curr->right,preorder,maxAllowed,size);
	}
}


template<class T>
void printBST(shared_ptr<node<T>> & curr){

	if(curr!=nullptr){
		cout<<curr->value<<endl;
		printBST(curr->left);
		printBST(curr->right);
	}	
}


template<class T,int N>
int arraySize(T (&array)[N]){
	return N;
}


int main(){

	int preorder[]={19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 37, 29, 31, 41, 47, 53};
	int n=arraySize(preorder);
	
	
	shared_ptr<node<int>> root=make_shared<node<int>>(preorder[0]);
	
	index=1;
	reconstructBST(root,preorder,1<<30-1,n);

	cout<<"preorder after built BST"<<endl;
	printBST(root);

	cout<<"Satisfies BST property? ans = "<<checkBSTproperty(root,1<<30-1)<<endl;



	return 0;
}
