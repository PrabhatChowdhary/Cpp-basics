#include <thread>
#include <iostream>
#include <mutex>
using namespace std;

mutex m;

void readbuf(int* i){
    int count=0;
        while(count<5){
        m.lock();

        cout<<"reading "<<*i<<endl;
        m.unlock();
        count++;
    }
}

void writebuf(int* i){
    
    
    m.lock();
    *i=*i+1;
    cout<<"writing "<<*i<<endl;
    m.unlock();
    
}

int main(){
    int* arr=new int[10]();
    //int arr[10]={0};
    
    thread threadA(readbuf,arr);
    thread threadB(writebuf,arr);
    thread threadC(writebuf,arr);

    threadA.join();
    threadB.join();
    threadC.join();
    
    return 0;
}
