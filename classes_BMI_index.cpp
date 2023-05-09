#include<iostream>
using namespace std;

//class person
class person{
    private:
        int age, weight, height;
        int static counter,id;
        float BMI(){
            cout<<"BMI index is "<<(100*100*weight)/(height*height)<<endl;
            return (100*100*weight)/(height*height);
        }
    public:
        void readvalues(bool RW);
        void isHealthy();
    //constructor function
        person(){
            cout<<" type in the age in years"<<endl;
            cin>>age;
            cout<<" type in the weight in kg"<<endl;
            cin>>weight;
            cout<<" type in the height in cm"<<endl;
            cin>>height;
            //counter=1001;
            counter=counter+1;
            id=counter;
            
            cout<<"id is "<<id<<endl;


        }
};

int person::counter = 1001;
int person::id = counter;

void person::readvalues(bool RW){
    if(RW==1){    
        cout<<" the age is ";
        cout<<age<<endl;
        cout<<" the weight is ";
        cout<<weight<<endl;
        cout<<" the height is ";
        cout<<height<<endl;
        cout<<" the id is ";
        cout<<id<<endl;
    }
    else{
            cout<<" type in the age in years"<<endl;
            cin>>age;
            cout<<" type in the weight in kg"<<endl;
            cin>>weight;
            cout<<" type in the height in cm"<<endl;
            cin>>height; 
    }
}

void person::isHealthy(){
    float BMI_value = BMI();
    
    //switch case cant be used directly for float
    if(BMI_value<18.5){
        cout<<"the person is underweight "<<endl;
        }
    else if(18.5<BMI_value && BMI_value<24.9){
        cout<<"the person is fit"<<endl;
        }
    else if(BMI_value>24.9){
        cout<<"the person is overweight"<<endl;
        }

}

int main(){
    cout<<"hello"<<endl;
    int x=12;
    int RW;
    person p1,p2,p3;
   
    //float check_BMI=p1.BMI();

    while(RW==1||RW==0){
        cout<<endl<<"to read person's details-1, to write person's details-0, to exit-2 "<<endl;
        cin>>RW;
        p1.readvalues(RW);
        p1.isHealthy();
    }
    return 0;
}
