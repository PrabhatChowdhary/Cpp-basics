#include <iostream>
using namespace std;

struct Treenode{
    int val;
    Treenode* left;
    Treenode* right;
    Treenode(): val(0), left(nullptr), right(nullptr){}
};

Treenode* invertTree(Treenode* node){

    if(node==NULL)
        return node;

    Treenode* tempNode = new Treenode();
    tempNode= node->left;
    node->left= node->right;
    node->right=tempNode;
    
    invertTree(node->left);
    invertTree(node->right);

    return node;
}

int main(){
    cout<<"hello"<<endl;
    
    return 0;
}
