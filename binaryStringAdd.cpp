// Online C++ compiler to run C++ program online
//https://leetcode.com/problems/add-binary/description/
#include <iostream>
#include <string>
using namespace std;

int main() {

    string a="001";
    string b="1111";
    
    int sizei=a.size()-1;
    int sizej=b.size()-1;
    int sizeo=max(sizei,sizej)+1;
    
    int* output=new int[sizeo];
    int c=0;
    
    for(int i=sizei;i>=0;i--){
        c+= (a[i]-'0')<<(sizei-i);
    
    }
    for(int j=sizej;j>=0;j--){
        c+= (b[j]-'0')<<(sizej-j);
    
    }
    cout<<c;
    for(int i=sizeo;i>=0;i--){
        output[i]=c%2;
        c/=2;
    }
    cout<<endl;
    for(int i=0;i<=sizeo;i++){
        cout<<output[i]<<" ";
    }
    return 0;
}   
