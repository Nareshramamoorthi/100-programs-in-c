#include <stdio.h>

int main() {
    int a,b;
    printf("Enter the frist no : ");
    scanf("%d",&a);
    printf("Enter the second no : ");
    scanf("%d",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("%d %d",a, b);
    return 0;
}
