// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int a=151;
    vector<int> a_bin;
    
    while (a>0){
        a_bin.push_back(a%2);
        a=a/2;
    }
    
    
    for(int i=0;i<a_bin.size()/2;i++){
        swap(a_bin[i],a_bin[(a_bin.size()-1)-i]);
        //cout<<a_bin[i];
    }
    
    for(int i=0;i<a_bin.size();i++){
        cout<<a_bin[i];
    }
    
    
    return 0;
}
