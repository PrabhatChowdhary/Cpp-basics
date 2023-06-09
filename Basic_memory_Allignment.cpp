//#pragma pack(push, 1) -> would give struc size 4(int) +1(char size) = 5 bytes
//#pragma pack(push, 2) -> would give struc size 4(int) +2(char size is 1 but size we are alligning memory per 2 bytes) = 6 bytes
//#pragma pack(push, 4) -> would give struc size 4(int) +4(char size is 1 but size we are alligning memory per 4 bytes) = 8 bytes
//---
#include <stdio.h>
#include <stdint.h>

#pragma pack(push, 4)
struct RGB {
    int red;
    char c0;
  //  uint8_t green;
//    uint8_t blue;
};
#pragma pack(pop)


int main() {
    printf("Size: %lu \n", sizeof(struct RGB));
    struct RGB rgb[2];
    printf("%p %p \n",&rgb[0],&rgb[1]);
    printf("differnce in address location is %d",&rgb[1]-&rgb[0]);
    return 0;
}
