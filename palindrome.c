#include <stdio.h>

int main() {
    int a,r=0,result;
    scanf("%d",&a);
    int ok=a;
    while(a!=0){
        int remainder=a%10;
         result=result*10+remainder;
        a=a/10;
    }
    printf("%d",result);
    if(result==ok){
        printf("it a palindrome");
    }
    else{
        printf("its not a palindrome");
    }
    return 0;
}
