// Online C++ compiler to run C++ program online
//input int, find output number of bits set as 1 in its binary representation
/*

1. Count the number of bits set to 1 in an integer:
   Given an integer, you need to count the number of bits that are set to 1 in its binary representation. This can be done using bitwise operations like AND and right shift.

2. Check if a number is a power of 2:
   Given an integer, you need to determine if it is a power of 2 or not. A number is a power of 2 if and only if it has only one bit set to 1 in its binary representation. You can check this by using bitwise operations like AND and subtraction.

3. Swap two numbers using bitwise operations:
   Given two integers, you need to swap their values without using any additional variables. This can be done using bitwise XOR operation.

4. Reverse the bits of an integer:
   Given an integer, you need to reverse its binary representation. This can be done by using bitwise operations like AND, OR, XOR, and bit shifting.

5. Find the missing number in an array:
   Given an array containing integers from 1 to n, with one number missing, you need to find the missing number. This can be solved using bitwise XOR operation.

*/

#include <iostream>

using namespace std;

int countOnes(int n){
    int count=0;
    while(n>0){
        n=n&(n-1); //removes 1 from lsb
        count++;
    }
    return count;
}


bool checkTwosPower(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void swapNums(int& x, int& y){//x=11001,
                              //y=01010
                            //x^y=10011
    y=x^y;
    x=x^y;
    y=x^y;
    
}

int reversebits(int n){ //reverse its binary representation
    //AND, OR, XOR, bitshifting
    int x=0;
    cout<<endl;
    while(n){
        if(x>0){
           x=x<<1;
        }
        x=x|(n & 1);
        n=n>>1;  
    }
    cout<<"return x is "<<x<<endl;
    return x;
}

int main() {
    int n=6;
    int x=44,y=3;
    
    cout<<"number of ones in binary are "<<countOnes(n)<<endl;
    cout<<"The number is 2's power "<<checkTwosPower(n)<<endl;
    swapNums(x,y);
    cout<<"after swap, x is "<<x<<" y is "<<y<<endl;
    cout<<"binary reversed number of "<<n<<" is "<<reversebits(n)<<endl;
    return 0;
}
