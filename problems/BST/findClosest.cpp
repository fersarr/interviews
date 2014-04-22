#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct node{
	T value;
	shared_ptr<node<T>> left,right;
	node(T val){
		value=val;
		left=nullptr;
		right=nullptr;
	}

};


int index;
int n;

template<class T>
void BST_fromPreorder(int preorder[],shared_ptr<node<T>> curr,T maxAllowed){
	
	if(preorder[index]<curr->value && index<n){
		curr->left=make_shared<node<T>>(preorder[index++]);
		BST_fromPreorder(preorder,curr->left,curr->value);
	}
	if(preorder[index]>curr->value && preorder[index]<maxAllowed && index<n){
		curr->right=make_shared<node<T>>(preorder[index++]);
		BST_fromPreorder(preorder,curr->right,maxAllowed);
	}
}


template<class T>
void printBST(shared_ptr<node<T>> curr){
	if(curr!=nullptr){
		cout<<curr->value<<endl;
		printBST(curr->left);
		printBST(curr->right);
	}
}


int answer=99;
int minDiff=1<<30-1;

template<class T>
T findClosest(shared_ptr<node<T>> curr,T value2find){
	if(curr!=nullptr){
		if(abs(value2find-curr->value)<minDiff){
			minDiff=abs(value2find-curr->value);
			answer=curr->value;
		}
		findClosest(curr->left,value2find);
		findClosest(curr->right,value2find);
	}
	return answer;
}


int main(){

	int preorder[]={19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 37, 29, 31, 41, 47, 53};
	n=sizeof(preorder)/sizeof(int);
	
	shared_ptr<node<int>> root=make_shared<node<int>>(preorder[0]);
	index=1;
	int big=1<<30-1;	
	
	BST_fromPreorder(preorder,root,big);

	//print preorder
	
	printBST(root);

	int value2find=39;
	cout<<"closest to "<<value2find<<" "<<findClosest(root,value2find)<<endl;



	return 0;
}




































