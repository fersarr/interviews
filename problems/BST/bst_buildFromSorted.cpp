#include <iostream>
#include <memory>
using namespace std;


//build a BST from a sorted array. The height should be minimized-> balance.
//Root should be n/2th element and recursively like that

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

int numbers[]={1,2,3,4,5,6,7};//,7,8,9,10,14,15,21,665,12132,1232143,999999999};

template<class T>
shared_ptr<node<T>> build_bst(shared_ptr<node<T>> & curr,int lo,int hi){
	cout<<"build "<<lo<<","<<hi<<endl;
	if(lo<hi){
		int mid=lo+(hi-lo)/2;
		curr=make_shared<node<T>>(numbers[mid]);
		curr->left=build_bst(curr->left,lo,mid);
		curr->right=build_bst(curr->right,mid+1,hi);
	}
	return curr;
}

template<class T>
void print_bst(shared_ptr<node<T>> &curr){
	if(curr!=nullptr){
		cout<<curr->value<<endl;
		print_bst(curr->left);
		print_bst(curr->right);
	}
}


int main(){

	int n=sizeof(numbers)/sizeof(int);
	
	
	shared_ptr<node<int>> root;
	
	root=build_bst(root,0,n);//if n-1 it doesnt get to last element for even and odd n

	print_bst(root);










	return 0;
}
