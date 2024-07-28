#include <stdio.h>
void modifyValue(int *ptr) {
    *ptr = 20; 
}
int main() {
    int value = 10;  
    int *ptr;       
    ptr = &value;   
    printf("Original value: %d\n", value);
    printf("Value through pointer: %d\n", *ptr);
    modifyValue(ptr);
    printf("Modified value: %d\n", value);
    printf("Value through pointer after modification: %d\n", *ptr);
    return 0;
}
