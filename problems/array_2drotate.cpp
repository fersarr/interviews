#include <iostream>
#include <iomanip>
using namespace std;

//rotate a 2d array (matrix) in O(N) time and o(1) space

#define MAX 10

int main()
{

	int array[MAX][MAX];
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			array[i][j]=j+i*MAX;
			
	cout<<"Original"<<endl;
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++)
			cout<<setw(3)<<array[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	
	
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

	cout<<"Rotated"<<endl;
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++)
			cout<<setw(3)<<array[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	


	return 0;
}
