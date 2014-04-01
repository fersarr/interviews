#include <iostream>

using namespace std;

void merge(int[],int[],int,int,int);

void mergesort(int a[], int b[], int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot);
        mergesort(a,b,pivot+1,high);
        
        merge(a,b,low,pivot,high);
    }
}

void merge(int a[], int b[], int low, int pivot, int high)
{
    int i1,i,i2,k;
    i1=low; //index for first half
    i=low; //index for complete subarray
    i2=pivot+1; //index for second half

    while((i1<=pivot)&&(i2<=high)){
        if(a[i1]<=a[i2]){ //if element in 1st half is smaller put it in tmp[]
            b[i]=a[i1];
            i1++;
        }
        else{
            b[i]=a[i2];
            i2++;
        }
        i++;
    }
    
    //copy the remaining. It could be leftovers from first half or second half
    if(i1>pivot){ //leftovers from 2nd half to copy to tmp[] because i1 is BIGGER than pivot, means i2 didn't go all the way
        for(k=i2; k<=high; k++){
            b[i]=a[k];
            i++;
        }
    }
    else{ //leftovers from 1st half to copy to tmp[]
        for(k=i1; k<=pivot; k++){
            b[i]=a[k];
            i++;
        }
    }
    
    //copy from tmp to original
    for(k=low; k<=high; k++) 
    	a[k]=b[k];
}

int main()
{
    int a[] = {12,10,43,23,-78,45,123,56,98,41,90,24};
    int num;

    num = sizeof(a)/sizeof(int);

    int b[num];

    mergesort(a,b,0,num-1);

    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    return 0;
}





















