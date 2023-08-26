#include <stdio.h>

void add(int x, int y){
    printf("%d\n",x+y);
}

int sub(int x,int y){
    return x-y;
}

void wrapper(void (*fun_w)(int x), int x){
    fun_w(x);
}

void fun(int a){
    printf("value of a is %d\n", a);
}

void print(void * val){
    
    printf("value is %d",*(int*)(val+ 2*sizeof(int)));//we use index multiplied by size of int since val is a void *
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

    void (*fun_ptr)(int) = &fun;
    (*fun_ptr)(2);
    fun(4);
    wrapper(fun,12);
    wrapper(*fun_ptr,22);
    
    int arr[10]={22,33,44,11,44,55,66,77,99,10};
   printf("%d\n",*(arr+2));//we can directly use index because arr is an int pointer
    print(arr);
    return 0;
}
