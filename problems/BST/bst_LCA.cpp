#include <iostream>
#include <memory>
#include <sstream>
using namespace std;

//given a binary tree
//find LCA in BST. x is LCA of a && b if a<x<b or x==b or x==a

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



//find LCA in BST. x is LCA of a && b if a<x<b or x==b or x==a
//a should be smaller than b ********
template<class T>
shared_ptr<node<T>> find_lca(shared_ptr<node<T>> & curr,shared_ptr<node<T>> & a,shared_ptr<node<T>> &b){
	
	if(b->value==curr->value || a->value==curr->value || (a->value<curr->value && curr->value<b->value) )
		return curr;
	else if(b->value<curr->value)
		return find_lca(curr->left,a,b);
	else
		return find_lca(curr->right,a,b);
}








int main(){

	int preorder[]={19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 37, 29, 31, 41, 47, 53};
	int n=arraySize(preorder);
	
	
	shared_ptr<node<int>> root=make_shared<node<int>>(preorder[0]);
	
	index=1;
	reconstructBST(root,preorder,1<<30-1,n);

	cout<<"preorder after built BST"<<endl;
	printBST(root);

	//a has to be smaller than b
	shared_ptr<node<int>> a=make_shared<node<int>>(13);
	shared_ptr<node<int>> b=make_shared<node<int>>(41);
	shared_ptr<node<int>> lca=find_lca(root,a,b);
	cout<<"LCA of "<<a->value<<" and "<<b->value<<" is "<<lca->value<<endl;



	return 0;
}
