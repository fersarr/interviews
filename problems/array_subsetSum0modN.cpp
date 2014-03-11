#include <iostream>
#include <set>
#include <map>
using namespace std;

//inside array of size N, find subset of elements such that the sum of its elements 
//add up to 0 mod N.  subsetSum % mod N ==0 
//if N == numberofElements in array there is AT LEAST ONE SOLUTION - if not, NP HARD

/*using prefix_sum[c] from 0,1,2...c :

At some point, two possibilities:
	1) prefix_sum[c]==0 -> this is the subset. One has to be it since subsetSums%N can be 0,1,2,3,...N-1
	2) prefix_sum[a]==prefix_sum[b] means from a to b the sum is 0 mod N. return that
	

*/


int main()
{

	//int numbers[]={123,123,1,213,421,3,12,3,5,4,5,4,23,324,43,234,2342,2,31,31,44,425,647575};
	//int numbers[]={429,334,62,711,704,763,98,733,721,995};
	int numbers[]={1,1,1,711,704,763,98,733,721,995};
	             //0,1,2,3  ,4  ,5  ,6 ,7
	int n=sizeof(numbers)/sizeof(int);
	cout<<"n= "<<n<<endl;
	
	map<int,int> subsetSums;
	
	int prefix_sum[n];
	
	prefix_sum[0]=numbers[0]%n;
	//cout<<"pref "<<prefix_sum[0]<<endl;
	
	for(int i=1;i<n;i++){
		prefix_sum[i]=(prefix_sum[i-1]+numbers[i]) % n;
		//cout<<"pref "<<prefix_sum[i]<<endl;
		if(prefix_sum[i]==0){
			cout<<"(1) subset 0 to "<<i<<endl;
			break;
		}
		if(subsetSums.find(prefix_sum[i])!=subsetSums.end()){
			cout<<"(2) subset "<<subsetSums[prefix_sum[i]]+1<<" to "<<i<<endl;
			break;
		}
		subsetSums[prefix_sum[i]]=i;
	}










	return 0;

}	
