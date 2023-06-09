// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    char A[]={'p','r'};
    char target='p';
    
    //do binary search to find which char would come just after target
    int m=0;
    int l=0;
    int r=sizeof(A)/sizeof(char)-1;
    while(l<r){
        m=(l+r)/2;
        if(target==A[m]){
            while(A[m]==target)
                m++;
            cout<<"next value is "<<A[m];
            return 0;
        }
            
        if(target<A[m])
            r=m;
        if(target>A[m])
            l=m+1;
    }
    cout<<"next value is "<<A[r];
    //l=5;
    //r=6;
    //m=5;
    
    //at exit if char  is not in list, l=r, and output should be A[r]
        
    
    return 0;
}
