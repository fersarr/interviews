#include <iostream>
using namespace std;

#define TESTS 9

int abs(int a){
	return a<0?-a:a;
}

//  a/b=c without operators
int divide(int a,int b){

	if(b==0){
		cout<<"INF"<<endl;
		return 1<<31-1;
	}
	
	int tmpa=abs(a);
	int tmpb=abs(b);
	
	bool neg=false;
	if(a<0 && b>0 || a>0 && b<0)
		neg=true;
		
	int count=0;
	while(tmpa-tmpb>=0){
		tmpa=tmpa-tmpb;
		count++;
	}

	if(neg)
		count=count*-1;
		
	return count;
}


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




int main()
{

	int a[TESTS]={8,42,88 ,8  ,-24,0 , 43, 32, -56};
	int b[TESTS]={4,6 ,9  ,24 ,-3 ,81, 0 , -8, 7};

	for(int i=0;i<TESTS;i++){
		cout<<a[i]<<" / "<<b[i]<<" = "<<divide_faster(a[i],b[i])<<endl<<endl;
	}









	return 0;
}







