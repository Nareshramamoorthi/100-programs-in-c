#include <stdio.h>

int main() {
    int a,temp;
    printf("Enter the farrenheit : ");
    scanf("%d",&a);
    temp =((a-32)*5)/9;
    printf("the current celsius is :%d",temp);
    return 0;
}
