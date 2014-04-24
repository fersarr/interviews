#include <iostream>
#include <memory>
using namespace std;



//given inorder and preorder(or postorder) traversal, reconstruct the binary tree
//to find the LCA of two given nodes a & b


#define INIT 42
template<class T>
struct node{
	T value;
	shared_ptr<node<T>> left,right;
	node(T _value){
		value=_value;
		left=nullptr;
		right=nullptr;
	}
	node(){
		value=INIT;
		left=nullptr;
		right=nullptr;
	}
};	

int size;
string preorder,inorder;
template<class T>
void reconstruct(shared_ptr<node<T>> & curr,int low,int high,int preorderIndex){
	
	//use low value to find the root in preorder. low is used BOTH in preorder for root and in inorder indicate start of right subtree
	T preorderRoot=preorder[preorderIndex]; //right part (end) of preorder has same nodes as inorder (different order)
	curr->value=preorderRoot;
	cout<<"recons "<<curr->value<<" low,high "<<low<<","<<high<<endl;
	
	int rootPos=inorder.find(preorderRoot);
	cout<<rootPos<<endl;
	//make left & right nodes to avoid having to link them later
	curr->left=make_shared<node<T>>();
	curr->right=make_shared<node<T>>();
	
	if(low!=high){
		if(rootPos-1>=low ) //low,high bounds
			reconstruct(curr->left ,low      ,rootPos-1,preorderIndex+1);
		if(rootPos+1<=high)
			reconstruct(curr->right,rootPos+1,high     ,preorderIndex+(rootPos-low)+1); //last param is to account for all the elements that are in left side and move preorderindex by that amunt
	}
}

template<class T>
void print_tree(shared_ptr<node<T>> & curr){
	if(curr!=nullptr){
		if(curr->value!=INIT)
			cout<<curr->value<<endl;
		print_tree(curr->left);
		print_tree(curr->right);
	}
}


//find LCA of two nodes a & b
//Algorithm: if both a&b are in the left subtree, then LCA is twoo (same for the right subtree)
template<class T>
shared_ptr<node<T>> find_LCA(shared_ptr<node<T>> & curr,shared_ptr<node<T>> a,shared_ptr<node<T>> b){
	if(curr==nullptr)
		return nullptr;
	else{
	
		//check if current is one of the nodes a or b. Also works for the case that A is LCA (or b)
		if(curr->value==a->value)
			return a;
		if(curr->value==b->value)
			return b;
		
		
		shared_ptr<node<T>> leftT=find_LCA(curr->left,a,b);
		shared_ptr<node<T>> rightT=find_LCA(curr->right,a,b);
		
		//if not null from right and left: curr is LCA
		if(leftT!=nullptr && rightT!=nullptr){
			return curr;
		}
	
		return leftT==nullptr?rightT:leftT; //return the one that's not null
	
	}

}



int main(){

	inorder= "FBAEHCDIG";
	preorder="HBFEACDGI";
	int size=inorder.length();
	
	shared_ptr<node<char>> root=make_shared<node<char>>();
	
	//int rootPos=inorder.find(preorder[0]);
	
	reconstruct(root,0,size-1,0);
	print_tree(root);

	shared_ptr<node<char>> a=make_shared<node<char>>('C');
	shared_ptr<node<char>> b=make_shared<node<char>>('I');
	shared_ptr<node<char>> lca=find_LCA(root,a,b);
	cout<<"LCA of given nodes is "<<lca->value<<endl;




	return 0;
}	
