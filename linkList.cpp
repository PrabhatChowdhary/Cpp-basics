#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    //constructor definition to come here
    node(int x=0,node* nextptr=nullptr){
        data=x;
        next=nextptr;
    }
};

void printLinklist(node* inputNode) {
    
    cout << "first data value of passed node is " << inputNode->data << endl;
   
        while (inputNode!=NULL){
            cout << inputNode->data << endl;
            
            if (inputNode->next != NULL)
            {
                inputNode = inputNode->next;
            }
            else break;
        }
                      
}

void appendNode(node* inputNode, int data) {
    cout << "checking input parsing in appendNode function " << inputNode->data << " and the input data is " << data << endl;
    node* newNode =  new node(data,inputNode->next);//not random address now with constructor
    //newNode->next = inputNode->next;
    inputNode->next = newNode;
    //newNode->data = data;
}

void reverveLinkList(node* inputNode) {

}

int main() {
    node* first = new node;  //allocate heap memory
    first->data = 1;

    node* second = new node;  //allocate heap memory
    second->data = 2;

    node* third = new node;  //allocate heap memory
    third->data = 3;

    first->next = second;
    second->next = third;
    third->next = nullptr;
    printLinklist(first);
    appendNode(second, 27);
    printLinklist(first);
    //cout << typeid(first).name();
    cout << "code has compiled" << endl;

    return 0;

}
