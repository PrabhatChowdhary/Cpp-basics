//https://leetcode.com/problems/evaluate-boolean-binary-tree/

// the implementation logic is similar to Binary Tree reversal
//We apply a recursive function call on node

#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;

    node(): val(0), left(nullptr), right(nullptr){}  
};

bool evalTree(node* root){

    if (root->val==0 or root->val==1){
        cout<<"loop 1 "<<endl;
        return root->val;}
    else if (root->val==2){
        cout<<"loop 2 "<<endl;    
        return evalTree(root->left) || evalTree(root->right); }
    else if (root->val==3){
        cout<<" loop 3 "<<endl;
        return evalTree(root->left) && evalTree(root->right);}
    else{
        cout<<"loop 4"<<endl;
        return 0;}

}

#include <iostream>
using namespace std;
int main(){

    cout<<"test hi"<<endl<<endl;
    node* first= new node();

    first->val=2;

    node* l1= new node();
    node* r1= new node();

    l1->val=1;
    r1->val=0;

    first->left=l1;
    first->right=r1;

    cout<<evalTree(first)<<" this was evalTree result"<<endl;
/*
    node* l2= new node();
    node* r2= new node();

    first->left->left=l2;
    first->left->right=r2;
    
    node* l3= new node();
    node* r3= new node();
    
    first->left->right->left=l3;
    first->left->right->right=r3;


    int a=1,b=1;
    bool c=a||b;
    cout<<c<<" this was c"<<endl;

//testing node functioning
    
    first->val=2;
    first->left->val=3;
    first->right->val=1;
    first->left->left=1;
    first->left->right=2;
    first->left->right->left=1;
    first->left->right->right=0;
*/
    return 0;
}

