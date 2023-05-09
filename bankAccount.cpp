#include <iostream>
#include <vector>
using namespace std;

enum class accountType{
    c,  //current
    s   //savings
};

class userClass{
    public:
    string userName;
    int userAccountNo;
    accountType acnType;
    int balanceAmount;

    
    userClass(){
        string temp;
        cout<<"Type in users name"<<endl;
        cin>>userName;
        static int counter=1000;
        counter ++;
        userAccountNo=counter;
        cout<<"your account number is "<<userAccountNo<<endl;
        cout<<"Type in the account type you want for user by c or s"<<endl;
        cin>>temp;
        if(temp == "c")
            acnType=accountType::c;
        else if(temp=="s")
            acnType=accountType::s;
        else{
            throw invalid_argument("Invalid input for accountType");
        }
        balanceAmount=0;
    }
};


userClass* findUser(vector<userClass>& usersVector, int accountNumber){
    cout<<"account number for search is"<<accountNumber<<endl;
    for (userClass& obj:usersVector){
        cout<<"for "<<obj.userName<<endl;
        cout<<"for "<<obj.userAccountNo<<endl;
        if(obj.userAccountNo == accountNumber){
            cout<<"if "<<obj.userName<<endl;
            return &obj;
        }
    }
    return nullptr; 
}



void depositMoney(vector<userClass>& usersVector, int accountNumber, int amount){
    
    userClass* foundUser=findUser(usersVector, accountNumber);
    if(foundUser!=nullptr){
        foundUser->balanceAmount=foundUser->balanceAmount + amount;
    }
    cout<<"new balance amount of user "<<foundUser->userName<<" after deposit is "<<foundUser->balanceAmount<<endl;
}

void withdrawMoney(vector<userClass>& usersVector, int accountNumber, int amount){
    
    userClass* foundUser=findUser(usersVector, accountNumber);
    if(foundUser!=nullptr & (foundUser->balanceAmount > 1000)){
        foundUser->balanceAmount=foundUser->balanceAmount - amount;
    }
    cout<<"new balance amount of user "<<foundUser->userName<<" after withdraw is "<<foundUser->balanceAmount<<endl;
}

void displayRecords(vector<userClass>& usersVector, int accountNumber){
    
    userClass* foundUser=findUser(usersVector, accountNumber);
    if(foundUser!=nullptr ){
        cout<<" For account number "<<accountNumber<<" ,the users name is "<<foundUser->userName<<endl;
        cout<<"  The balance amount is "<<foundUser->balanceAmount<<endl;
        if (foundUser->acnType==accountType::c)
            cout<<"the users account type is c"<<endl;
        else
            cout<<"the users account type is s"<<endl;
    }
    
}


int main(){
    cout<<"test basic"<<endl;
    userClass user1test;
    
    //making a vector of users so that we can also search on the user account later
    vector<userClass> usersVector;

    userClass user2;
    userClass user3;
    userClass user4;
    
    usersVector.push_back(user2);
    usersVector.push_back(user3);
    usersVector.push_back(user4);

    userClass* foundUser=findUser(usersVector,1002);
    depositMoney(usersVector,1002,3999);
    withdrawMoney(usersVector,1002,500);
    displayRecords(usersVector,1002);
    cout<<"user name of the found user is "<<foundUser->userName<<endl;
    return 0;
}
