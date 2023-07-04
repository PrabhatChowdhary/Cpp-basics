#include <thread>
#include <iostream>
#include <mutex>
using namespace std;

mutex m;

void readbuf(int* i,int index){
    int count=0;
        while(count<5){
        m.lock();

        cout<<"reading "<<i[index]<<endl;
        m.unlock();
        count++;
    }
}

void writebuf(int* i,int index,int val){
    
    
    m.lock();
    i[index]=val;
    cout<<"writing "<<val<<endl;
    m.unlock();
    
}

int main(){
    int* arr=new int[10]();
    //int arr[10]={0};
    int index=2,val=49;
/*
    cout<<"write the index you want to write "<<endl;
    cin>>index;
    cout<<"what value should be written on that index "<<endl;
    cin>>val;
*/
    
    thread threadA(readbuf,arr,index);
    thread threadB(writebuf,arr,index,val);
    thread threadC(writebuf,arr,index,val);

    threadA.join();
    threadB.join();
    threadC.join();
    
    return 0;
}
