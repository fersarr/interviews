#include <iostream>
#include <memory>
#include <stack>
using namespace std;

//Traverse the tree (preorder) without recursion

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


int index;
template<class T> //no need to track min allowed because of BST property (may be for post order is opposite?)
void bst_fromPreorder_faster(shared_ptr<node<T>>  &curr,int preorder[],int n,shared_ptr<node<T>>  &previous, bool went_left,int maxAllowed){
	
	
	
	if(curr==nullptr){ //not here first time because root is initialized
		curr=make_shared<node<T>>(preorder[index++]);
		cout<<"Made "<<curr->value<<endl;
		if(went_left==true)
			previous->left=curr;
		else
			previous->right=curr;
	}
	
	if(index==n){
		cout<<"done"<<endl;
		return; //all array done
	}
	
	
	//not using if-else , just ifs because we can add to current and to its childs (left and right)
	if(preorder[index]<=curr->value){//left
			cout<<"L: go left "<<curr->value<<endl;
			bst_fromPreorder_faster(curr->left,preorder,n,curr,true,curr->value);
	}
											//nulptr if curr is root
	if(preorder[index]>curr->value && (previous==nullptr || preorder[index]<maxAllowed) ){ //if its bigger than current and bigger than previous, it goes up one level in the recursion
			cout<<"L: go right "<<curr->value<<endl;
			bst_fromPreorder_faster(curr->right,preorder,n,curr,false,maxAllowed);
	}

	
}


template<class T>
void print_BST_preorder(shared_ptr<node<T>> & curr){
	
	if(curr!=nullptr){
		cout<<curr->value<<endl;
		print_BST_preorder(curr->left);
		print_BST_preorder(curr->right);
	}
	
}


int main(){
	int preorder[]={19,7,3,2,5,11,17,13,43,23,37,29,31,41,47,53};
	int n=sizeof(preorder)/sizeof(int);
	
	shared_ptr<node<int>> root; 
	

	index=0;
	root=make_shared<node<int>>(preorder[index++]);
	shared_ptr<node<int>> shared_null;
	cout<<"Root "<<root->value<<endl;
	int big=1e9;
	bst_fromPreorder_faster(root,preorder,n,shared_null,false,big);
	cout<<"reached "<<index<<"/"<<n<<endl;
	
	//cout<<"Preorder"<<endl;
	//print_BST_preorder(root);

	typedef shared_ptr<node<int>> treenode;
	
	treenode tmp;
	
	stack<treenode> s;
	s.push(root);
	while(!s.empty()){
		tmp=s.top();
		s.pop();
		if(tmp!=nullptr)
			cout<<"Val: "<<tmp->value<<endl;
		if(tmp->right!=nullptr)
			s.push(tmp->right);
		if(tmp->left!=nullptr)
			s.push(tmp->left);
	}






	return 0;
}






















