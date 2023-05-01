#include<iostream>
using namespace std;

//class person
class person{
    private:
        int age, weight, height;
    public:
        void readvalues(bool RW);
};

void person::readvalues(bool RW){
    if(RW==1){    
        cout<<" the age is ";
        cout<<age<<endl;
        cout<<" the weight is ";
        cout<<weight<<endl;
        cout<<" the height is ";
        cout<<height<<endl;
    }
    else{
            cout<<" type in the age"<<endl;
            cin>>age;
            cout<<" type in the weight"<<endl;
            cin>>weight;
            cout<<" type in the height"<<endl;
            cin>>height; 
    }
}

int main(){
    cout<<"hello"<<endl;
    int x=12;
    int RW;
    person p1;
    while(RW==1||RW==0){
        cout<<endl<<"to read person's details-1, to write person's details-0, to exit-2 "<<endl;
        cin>>RW;
        p1.readvalues(RW);
    }
    return 0;
}
