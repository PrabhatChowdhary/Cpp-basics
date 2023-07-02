#include <iostream>
using namespace std; 


void merge(int* A,int sizeA,int* B,int sizeB,int* C){
    

    int pa=0,pb=0;
    
    for(int i=0;i<sizeA+sizeB;i++){
        if((pb==sizeB) ||((pa<sizeA) &  (A[pa]<B[pb]))){
            C[i]=A[pa];
            pa++;
        }
        else{
            C[i]=B[pb];
            pb++;
        }
        
    }
    
} 


void sort(int* A,int size){
    
    if(size<=1)
        return;
    
    int* B1=new int[size/2];
    int* B2=new int[size - size/2];
  
    for (int i=0; i<size;i++){
        if(i<size/2)
            B1[i]=A[i];
        else
            B2[i-size/2]=A[i];
    }
    sort(B1,size/2);
    sort(B2,size - size/2);
    
    merge(B1,size/2,B2,size-(size/2),A);
}

int main() {
        
        int A[]={22,1,3,5,0,11,2,55,78,45,51,522,12,10};
        //int A[]={10,20,0,1};
        int size=sizeof(A)/sizeof(int);
       
        sort(A,size);
       
        for(int i=0;i<size;i++)
            cout<<A[i]<<" ";
        
        return 0;
}
