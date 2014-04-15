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
	
		//to break BST property
		/*if(curr->value==17){
			curr->value=20; //not its bigger than max Allowed
		}*/
		/*if(curr->value==3){
			curr->value=8; //now left child is bigger than parent
		}*/
		/*if(curr->value==47){
			curr->value=42; //not right child is smaller than parent
		}*/
		
		cout<<curr->value<<endl;
		printBST(curr->left);
		printBST(curr->right);
	}	
}


template<class T,int N>
int arraySize(T (&array)[N]){
	return N;
}


template<class T>
bool checkBSTproperty(shared_ptr<node<T>> & curr,int maxAllowed){
	
	//to break BST property
	
	bool ans=curr->value <maxAllowed;
	
	if(curr!=nullptr){
		if(curr->left!=nullptr){
			ans=ans && (curr->left->value < curr->value) && checkBSTproperty(curr->left,curr->value); 
		}
		if(curr->right!=nullptr){
			ans=ans && (curr->right->value > curr->value) && checkBSTproperty(curr->right,maxAllowed); 
		}

	}
	
	return ans;

}

int main(){

	int preorder[]={19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 37, 29, 31, 41, 47, 53};
	int n=arraySize(preorder);
	
	
	shared_ptr<node<int>> root=make_shared<node<int>>(preorder[0]);
	
	index=1;
	reconstructBST(root,preorder,1<<30-1,n);

	cout<<"preorder after built BST"<<endl;
	printBST(root);

	//to test if in many cases, UNCOMMENT lines in printBST()
	cout<<"Satisfies BST property? ans = "<<checkBSTproperty(root,1<<30-1)<<endl;



	return 0;
}
