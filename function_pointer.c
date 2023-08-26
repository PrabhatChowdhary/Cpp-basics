#include <stdio.h>

void add(int x, int y){
    printf("%d\n",x+y);
}

int sub(int x,int y){
    return x-y;
}

int main() {
    // Write C code here
    add(2,3);
    //declaring a function pointer for add function
    void (*adder_ptr)(int, int) = &add; //=add can also be used
    (*adder_ptr)(1,2);//adder_ptr can also be used
    //calling sub function
    printf("%d\n",sub(3,20));
    //declaring a pointer for sub funtion
    int (*sub_ptr)(int, int) = &sub;
    printf("%d\n",(*sub_ptr)(44,11));
    return 0;
}
