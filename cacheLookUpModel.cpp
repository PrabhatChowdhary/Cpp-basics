// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>
using namespace std;

//Question
//use modular programming
//write cache eviction scheme for LRU
//write a data structure to implement cache lookup

//Solution
/*class cacheAddressLookupTable has been defined

public variables- 

LastUsedIndex which is a list to keep addresses in a sequence that most recently used addr is towards the list end and the last access address is towareds list start

size is predefined as 4. It can be changed by user by calling SetSize function.

addNewAddr() fnc adds a new address to list. and if address is already present then deletes the address's old location and puts it on MRU.

printAllAddr() fnc prints all addresses in sequence of their use- LRU to MRU.

doCompute() fnc is a opeartor to mention a partical addr has been used for computation. If the addr was not present in the list then, memory controller will update the caches and add the address in the LastUsedIndex cache list.
        if address was already present in the cache list then it is assumed that controller will not automatically update the memory and cache vs memory values will be different. To indicate that, there is a dirty bit which will be set.

printDirtyBit()- will print the state of the dirty bit.

private variables

dirtyBit- used to indicate if cache and memory are not in sync

updateDirtyBit()- fnc will be used to set the dirty bit to 1.


*/
class cacheAddressLookupTable{
public:
    list<int> LastUsedIndex;
    int size=4;
    
    void SetSize(int x=4){
        size=x;
    }
    void addNewAddr(int addr){
        list<int>::iterator it=LastUsedIndex.begin();
        while(it!=LastUsedIndex.end()){
            if(*it==addr){
                LastUsedIndex.erase(it);
                break;
            }
            ++it;
        }
        if(LastUsedIndex.size()<size)
            LastUsedIndex.push_back(addr);
        else{
            LastUsedIndex.erase(LastUsedIndex.begin());
            LastUsedIndex.push_back(addr);
        }
    }
    void printAllAddr(){
        cout<<"Addresses in cache are- ";
        for(int x:LastUsedIndex)
            cout<<x<<" ";
        cout<<endl;
    }
    
    void doCompute(int addr){
        list<int>::iterator it=LastUsedIndex.begin();
        while(it!=LastUsedIndex.end()){
            if(*it==addr){
                updateDirtyBit();
                //dirtyBit=true; this can also be done rather than making a seperate fnc to updateDirtyBit.
                break;
            }
            ++it;
        }
        if(it==LastUsedIndex.end())
            addNewAddr(addr);
    }
    
    void printDirtyBit(){
        cout<<"dirty bit is "<<dirtyBit<<endl;
    }
    
private:
    bool dirtyBit=false; 
    void updateDirtyBit(){
        dirtyBit=true;
    }
};

int main() {
    cacheAddressLookupTable t1;
    //t1.SetSize();
    t1.addNewAddr(11);
    t1.addNewAddr(22);
    t1.addNewAddr(33);
    
    t1.printAllAddr();
    
    //calling address 11 and then adding new addr so that 22 becomes LRU
    t1.addNewAddr(11);
    t1.printAllAddr();
    
    t1.addNewAddr(44);
    t1.addNewAddr(55);
    t1.printAllAddr();
    
    //do compute and dirty bit
    t1.printDirtyBit();
    //cout<<t1.dirtyBit<<endl; //this won't work because dirty bit is a private member
    cout<<"do compute on addr 66"<<endl;
    t1.doCompute(66);
    t1.printAllAddr();
    t1.printDirtyBit();
    t1.doCompute(66);
    t1.printDirtyBit();
    return 0;
}
