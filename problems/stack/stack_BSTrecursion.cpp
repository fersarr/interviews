#include <iostream>
#include <memory>
using namespace std;

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

template<class T>
void insert(shared_ptr<node<T>> &root,int value){
	shared_ptr<node<T>> curr=root,previous;
	
	bool left=true;
	
	while(curr!=nullptr){
		previous=curr;
		cout<<"curr value: "<<curr->value<<endl;
		if(value<=curr->value){ //go left
			curr=curr->left;
			left=true;
		}
		else{
			curr=curr->right;
			left=false;
		}
	}

	if(curr==nullptr){ //here create new node
		curr=make_shared<node<T>>(value);
		if(left)
			previous->left=curr;
		else
			previous->right=curr;
	}
}



template<class T>
void bst_fromPreorder(shared_ptr<node<T>> &root,int preorder[],int n){
	root=make_shared<node<T>>(preorder[0]);
	
	for(int i=1;i<n;i++){
		cout<<"insert "<<preorder[i]<<endl;
		insert(root,preorder[i]);			
		cout<<"------------------------"<<endl<<endl;				
	}
}

int index;
template<class T>
void bst_fromPreorder_faster(shared_ptr<node<T>>  &curr,int preorder[],int n,shared_ptr<node<T>>  &previous, bool went_left,int maxAllowed,int minAllowed){
	
	
	
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
			bst_fromPreorder_faster(curr->left,preorder,n,curr,true,curr->value,minAllowed);
	}
											//nulptr if curr is root
	if(preorder[index]>curr->value && (previous==nullptr || preorder[index]<maxAllowed) ){ //if its bigger than current and bigger than previous, it goes up one level in the recursion
			cout<<"L: go right "<<curr->value<<endl;
			bst_fromPreorder_faster(curr->right,preorder,n,curr,false,maxAllowed,curr->value);
	}

	
/* 	else if(went_left==false){ //this is a RIGHT child
		//not using if-else , just ifs because we can add to current and to its childs (left and right)
		
											//nulptr if curr is root. this part is not needed if preorder holds BST property
		if(preorder[index]<=curr->value ){//&& (previous==nullptr || preorder[index]>minAllowed) ){//left child if its smaller than current and bigger than previous, can't goes up one level in the recursion because this is preorder of a tree with BST property
				cout<<"R: go left "<<curr->value<<endl;
				bst_fromPreorder_faster(curr->left,preorder,n,curr,true,curr->value,minAllowed);
		}
												//nulptr if curr is root
		if(preorder[index]>curr->value && (previous==nullptr || preorder[index]<maxAllowed)){ 
				cout<<"R: go right "<<curr->value<<endl;
				bst_fromPreorder_faster(curr->right,preorder,n,curr,false,maxAllowed,curr->value);
		}
	} */
	
	
	
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
	
	//bst_fromPreorder(root,preorder,n);
	
	index=0;
	root=make_shared<node<int>>(preorder[index++]);
	shared_ptr<node<int>> shared_null;
	cout<<"Root "<<root->value<<endl;
	int big=1e9;
	bst_fromPreorder_faster(root,preorder,n,shared_null,false,big,-big);
	cout<<"reached "<<index<<"/"<<n<<endl;
	
	cout<<"Preorder"<<endl;
	print_BST_preorder(root);









	return 0;
}
