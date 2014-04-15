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



template<class T>
void bst_insert(shared_ptr<node<T>> & curr,T value){
	if(curr!=nullptr){
		if(value< curr->value){ //go left
			if(curr->left==nullptr){
				curr->left=make_shared<node<T>>(value);
			}
			else{
				bst_insert(curr->left,value);
			}
		}
		else{ //go right
			if(curr->right==nullptr){
				curr->right=make_shared<node<T>>(value);
			}
			else{
				bst_insert(curr->right,value);
			}
		}
	}
}


//bst delete node and maintain BST property
/*3 cases:
node is leaf 		-> just delete the link to it
node has 1 subtree 	-> point the parent of the node to the child of the node
node has 2 subtrees -> update the value using the biggest in left subtree or smallest in right subtree 
Note: The largest value in the left subtree will never have two subtrees. Why? Because if it's the largest value it cannot have a right subtree.
*/
//val= value to delete
template<class T>
void bst_delete(shared_ptr<node<T>> curr,shared_ptr<node<T>> parent,bool isLeft,int val){
	
	//cout<<"searching "<<curr->value<<endl;
	if(curr!=nullptr){
		if(curr->value==val){ //this is the node
			//IT'S A LEAF
			if(curr->left==nullptr && curr->right==nullptr){ //it's a leaf
				if(isLeft){
					parent->left=nullptr;
				}
				else{
					parent->right=nullptr;
				}
			}
			//ONLY ONE SUBTREE
			else if(curr->left!=nullptr && curr->right==nullptr){ //only one subtree(left)
				//cout<<"deleting "<<curr->value<<" isLeft "<<isLeft<<" parent "<<parent->value<<endl;
				if(isLeft){
					parent->left=curr->left;
				}
				else{
					parent->right=curr->left;
				}
			}
			else if(curr->left==nullptr && curr->right!=nullptr){ //only one subtree(right)
				if(isLeft){
					parent->left=curr->right;
				}
				else{
					parent->right=curr->right;
				}
			}
			//TWO SUBTREES, USE SMALLEST IN RIGHT SUBTREE
			else{
				shared_ptr<node<T>> rightCurr=curr->right ,rightCurrParent=curr;
				while(rightCurr->left!=nullptr){
					rightCurrParent=rightCurr;
					rightCurr=rightCurr->left;
				}
				
				curr->value=rightCurr->value; //update the value of the node to be deleted
				if(curr->right==rightCurr){ //the smallest on right subtree is the first node to the right
					curr->right=rightCurr->right;//update the deleted node's right link (doens't have left because that imply theres a smaller node) to avoid having the new value duplicated			
				}
				else{
					rightCurrParent->left=rightCurr->right; //update to the smallest's right subtree or delete link to smallest (if it didn't have a right subtree)
				}
		
			}
			//IT'S THE ROOT
			
		}
		else{
			if(val<curr->value){
				bst_delete(curr->left,curr,true,val);
			}
			else{
				bst_delete(curr->right,curr,false,val);
			}
		}
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

	//bst_insert(root,114);
	//bst_insert(root,-9);
	//bst_insert(root,18);
	//bst_insert(root,38);
	
	cout<<"AFTER INSERT: preorder after built BST"<<endl;
	printBST(root);

	cout<<"After DELETE"<<endl;

	//bst_delete(root,root,false,11);//only has 1 subtree: right (if inserts are commented)
	//bst_delete(root,root,false,17);//only has 1 subtree: left
	//bst_delete(root,root,false,31); //leaf
	//bst_delete(root,root,false,7); //has both subtrees. choose smallest in rightsubtree. In this case we wupdate with first node to the right
	
	//bst_insert(root,22); //this is for the next delete case
	//bst_delete(root,root,false,23); //has both subtrees. choose smallest in rightsubtree. In this case, update with NOT FIRST node to right
	
	bst_delete(root,root,false,19); //delete root
	printBST(root);

	return 0;
}
