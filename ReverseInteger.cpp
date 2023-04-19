#include <iostream>
#include <vector>
using namespace std;

int revInt(int num){
    //determine the number of digits of intput integer- 
    //max size is 4 bytes, i.e. 32 bits
    //in decimals, that would be 2^31 -1 = 2147483647
    int flag=0;
    if (num<0){
        num=num*(-1);
        flag=1;
    }

    int i=1;

    //finding the number of digits of input
    if(num<10)
    return num;
    else
    while(num>i){
        i=i*10;
    }
    cout<<"i is "<<i<<endl;

    i=i/10;
    int k=1;
    int frac;
    int newNum, opnum;
    opnum=0;
    newNum=num;
    cout<<"num  "<<num<<endl;
    cout<<"i is "<<i<<endl;
    while(i>=1){
        
        frac=newNum/i;
        newNum=newNum-(frac*i);
        opnum=opnum+(frac*k);
        i=i/10;
        k=k*10;

        cout<<"frac "<<frac<<"  newNum  "<<newNum<<"  opnum  "<<opnum<<" i "<<i<<" k "<<k<<endl;
    }
    
    cout<<"the reversed num is "<<opnum<<endl;

    if (flag==1)
    return opnum*(-1);
    else
    return opnum;
}


int main(){
    cout<<"hello again"<<endl<<"size of int is ";
    int x=1000;
    cout<<sizeof(x)<<endl<<"input is "<<x<<endl;

    revInt(x);
    return 0;
}

