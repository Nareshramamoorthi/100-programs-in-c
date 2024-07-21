// Online C compiler to run C program online

#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    if(a>90){
        printf("%d is first grade ",a);
    }
    else if(80<a){
        printf("%d is the first tier second grade",a);
    }
       else if(60<a){
        printf("%d is second grade",a);
    }
       else if(50<a){
        printf("%d is third grade",a);
    }
    else{
        printf("fail");
    }
    return 0;
}
