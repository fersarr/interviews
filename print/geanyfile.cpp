//ADDITION without operators, only binary
int add(int a,int b)
{
	unsigned int tmp_a=a,tmp_b=b; //use this temporary and each iteration shift it right.
					 		  //this way we avoid doing all 32 bits if all zero	
	
	int ans=0;
	int bits=sizeof(int)*8;
	int carry_in=0,carry_out=0;
	int ak,bk,k=1; //k left shifts 1 in each iteration and masks a and b
	
	while(tmp_a || tmp_b){
		ak=a&k;
		bk=b&k;
		carry_out=(ak & bk) | (ak & carry_in) | (bk & carry_in); //adding possibilities that give a carry out
		ans|=ak^bk^carry_in; //toggle
		carry_in=carry_out<<1;
		k<<=1;
		tmp_a>>=1;
		tmp_b>>=1;
	}

	ans|=carry_in; //last carry_in
	
	return ans;;
}


--------------------------------------------------------

	//2D rotate in place
	
	for(int i=0;i<MAX/2;i++){ //half the rows
		for(int j=i;j<MAX-1-i;j++){ //columns each time one less
			int tmp=array[i][j];
			array[i][j]=array[MAX-1-j][i];
			array[MAX-1-j][i]=array[MAX-1-i][MAX-1-j];
			array[MAX-1-i][MAX-1-j]=array[j][MAX-1-i];
			array[j][MAX-1-i]=tmp;
		}
	}
	
-------------------------------------------------------

//  a/b=c without operators
int divide_faster(int a, int b){
	if(b==0){
		cout<<"INF"<<endl;
		return 1<<31-1;
	}
	
	unsigned int tmpa=abs(a);
	unsigned int tmpb=abs(b);
	
	bool neg =false;
	if(  (a<0 && b>0) || (a>0 && b<0) )
		neg=true;
		
	int k=1;
	int count=0;
	
	while(tmpa>=tmpb){
		//cout<<tmpa<<" "<<tmpb<<endl;
		int power=1; //starts in 1, if doesn't go in while power-1 is used
		
								    //this second part is to avoid overflow
		while( (tmpb<<power)<=tmpa && (tmpb<<power) >= (tmpb<<power-1)){ //make it faster by decreasing by b^k
			power++;
		}
	
		tmpa=tmpa-(tmpb<<(power-1));
		
		count=count+(1U<<(power-1)); 
	}
	
	if(neg)
		count=count*-1;
	
	return count;
}


-----------------------------------------------

setCounter=0;
dfs(0,0);
	
	
//set power set
void dfs(int index,int lowestAllowed){
	
	for(int i=0;i<index;i++){
		cout<<printSet[i];
	}
	cout<<endl;
	setCounter++;
	
	for(int i=lowestAllowed;i<setSize;i++){
		printSet[index]=numbers[i];
		dfs(index+1,i+1);
	}
	
}



------------------
//binary search

int lowerBound(int numbers[],int size,int k){

	int l=0;
	int r=size-1;
	int m;
	int saved=-1;
	
	while(l<=r){
		m=l+(r-l)/2;
		if(numbers[m]>=k){ 
			saved=m;
			r=m-1;
		}
		else{
			l=m+1;
		}
	}

	return saved; //-1 if not found
}



--------------
//list median

template<class T>
shared_ptr<node<T>> list_median(shared_ptr<node<T>> & head){
	shared_ptr<node<T>> slow=head,fast=head;
	
	while(fast!=nullptr){
		fast=fast->next;
		if(fast!=nullptr){
			slow=slow->next;
			fast=fast->next;
		}
	}	
	
	return slow;
}


