#include <iostream>
using namespace std;


#define ADDTESTS 6

//implement multiplication without using any +,-,/,*
//a*b=c



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






//MULTIPLICATION using addition
int multiply(unsigned int a,unsigned int b) //unsigned because of right shift
{
	int ans=0;
	
	/*  time: o(b)
	for(int i=0;i<b;i++){
		ans=add(ans,a);
	}
	*/
	
	//faster (at most 32 (bits) times) :
	
	
	//WHY DOES THIS WORK WITH NEGATIVES?!
	
	
	
	while(b!=0){
		cout<<"sum "<<ans<<" a "<<a<<endl;
		if(b&1==1) //if the bit is set
			ans=add(ans,a);
		a<<=1; //each time the bit accounts for double
		b>>=1; //consume one bit at a time
	}
	



	return ans;
}







int main()
{
	int a[ADDTESTS]={1,5,63 ,8  ,-3,0};
	int b[ADDTESTS]={2,3,207,-12,-4,81};
	
	for(int i=0;i<ADDTESTS;i++){
		cout<<a[i]<<" + "<<b[i]<<" = "<<add(a[i],b[i])<<endl;
	}

	cout<<"Multiply "<<endl;
	
	for(int i=0;i<ADDTESTS;i++){
		cout<<a[i]<<" * "<<b[i]<<" = "<<multiply(a[i],b[i])<<endl;
	}






	return 0;
}
























